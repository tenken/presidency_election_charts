<?php
/**
 * @file
 * presidency_election_charts.ds.inc
 */

/**
 * Implements hook_ds_custom_fields_info().
 */
function presidency_election_charts_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'highcharts_usa_full_map';
  $ds_field->label = 'Highcharts - USA Full Map';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = 'election|*';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<?php

// Add highcharts dependencies
// Example from:
// http://jsfiddle.net/gh/get/jquery/1.9.1/highslide-software/highcharts.com/tree/master/samples/maps/demo/us-data-labels/
//drupal_add_js(\'http://code.highcharts.com/highcharts.js\', \'external\');
drupal_add_js(\'https://code.highcharts.com/maps/highmaps.js\', \'external\');
drupal_add_js(\'https://code.highcharts.com/maps/modules/data.js\', \'external\');
drupal_add_js(\'https://code.highcharts.com/maps/modules/exporting.js\', \'external\');
drupal_add_js(\'https://code.highcharts.com/mapdata/countries/us/custom/us-small.js\', \'external\');


$js =<<<EOFJS
jQuery(document).ready(function () {

 // Load the data from the HTML table and tag it with an upper case name used for joining
    var data = [],
        // Get the map data
        mapData = Highcharts.geojson(Highcharts.maps[\'countries/us/custom/us-small\']);

    Highcharts.data({
        table: document.getElementById(\'data\'),
        startColumn: 1,
        startRow: 1,
        complete: function (options) {
            jQuery.each(options.series[0].data, function () {
                data.push({
                    ucName: this[0],
                    value: this[1]
                });
            });
        }
    });

    // Process mapdata
    jQuery.each(mapData, function () {
        var path = this.path,
            copy = {
                path: path
            };

        // This point has a square legend to the right
        if (path[1] === 9727) {

            // Identify the box
            Highcharts.seriesTypes.map.prototype.getBox.call(0, [copy]);

            // Place the center of the data label in the center of the point legend box
            this.middleX = ((path[1] + path[4]) / 2 - copy._minX) / (copy._maxX - copy._minX); // eslint-disable-line no-underscore-dangle
            this.middleY = ((path[2] + path[7]) / 2 - copy._minY) / (copy._maxY - copy._minY); // eslint-disable-line no-underscore-dangle

        }
        // Tag it for joining
        this.ucName = this.name.toUpperCase();
    });




    // Initiate the chart
    jQuery(\'#prez_map\').highcharts(\'Map\', {

        title: {
            text: \'US unemployment rate 2015\'
        },

        subtitle: {
            text: \'Small US map with data labels\'
        },

        mapNavigation: {
            enabled: true,
            enableButtons: false
        },

        xAxis: {
            labels: {
                enabled: false
            }
        },

        colorAxis: {},

        series: [{
            mapData: mapData,
            data: data,
            joinBy: \'ucName\',
            name: \'Unemployment rate per 2015\',
            states: {
                hover: {
                    color: \'#BADA55\'
                }
            },
            dataLabels: {
                enabled: true,
                formatter: function () {
                    return this.point.properties[\'hc-a2\'];
                },
                style: {
                    fontSize: \'10px\'
                }
            },
            tooltip: {
                valueSuffix: \'%\'
            }
        }, {
            type: \'mapline\',
            data: Highcharts.geojson(Highcharts.maps[\'countries/us/custom/us-small\'], \'mapline\'),
            color: \'silver\'
        }]
    });
});
EOFJS;
drupal_add_js($js, \'inline\');

$content = array(
  \'highcharts_map\' => array(
    \'#type\' => \'markup\',
    \'#markup\' => "<div id=\'prez_map\'></div>"
  ),
);
return drupal_render($content);',
      'format' => 'php_code',
    ),
    'use_token' => 0,
  );
  $export['highcharts_usa_full_map'] = $ds_field;

  return $export;
}
