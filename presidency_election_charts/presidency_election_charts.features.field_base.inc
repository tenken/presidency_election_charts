<?php
/**
 * @file
 * presidency_election_charts.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function presidency_election_charts_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_election_map_configuration'.
  $field_bases['field_election_map_configuration'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_election_map_configuration',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'paragraphs',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'paragraphs',
  );

  return $field_bases;
}
