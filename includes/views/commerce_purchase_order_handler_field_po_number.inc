<?php
class commerce_purchase_order_handler_field_po_number extends views_handler_field {
  function init(&$view, &$options) {
    parent::init($view, $options);

    $this->additional_fields['order_id'] = 'order_id';
  }

  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }

  function render($values) {
    $order_id = $this->get_value($values, 'order_id');
    $text = '';
    $text = commerce_purchase_order_number_from_order_id($order_id);
    return $text;
  }
}
