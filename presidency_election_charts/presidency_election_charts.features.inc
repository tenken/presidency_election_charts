<?php
/**
 * @file
 * presidency_election_charts.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function presidency_election_charts_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_paragraphs_info().
 */
function presidency_election_charts_paragraphs_info() {
  $items = array(
    'electoral_map' => array(
      'name' => 'electoral map',
      'bundle' => 'electoral_map',
      'locked' => '1',
    ),
  );
  return $items;
}
