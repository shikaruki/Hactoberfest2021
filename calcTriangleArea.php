<?php

class Calculate {
    public function calcTriangleArea($a, $b){
        $area = 0.5 * $a * $b;
        return $area;
    }
}

$rect = new Calculate;
echo $rect->calcTriangleArea(3, 7);