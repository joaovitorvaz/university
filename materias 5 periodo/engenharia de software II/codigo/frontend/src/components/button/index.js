import React from 'react';
import {DynamicButton} from "./styles";

export default function Button({ onClick, buttonName, size, color, block }) {
  return (
    <DynamicButton onClick={onClick} size={size} disabled={block}>{buttonName}</DynamicButton>
  );
}