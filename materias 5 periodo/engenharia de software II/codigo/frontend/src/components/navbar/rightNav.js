import React from 'react';
import { Ul, Redirect, Line } from './styles';
import data from './data';

export default function RightNav({ open, setOpen }) {
  return (
    <Ul open={open}>
      {data.map((item) => (
        <li key={item.id}>
          <Redirect
            onClick={() => window.innerWidth <= 850 && setOpen(!open)}
            to={item.link}
          >
            {item.name}
          </Redirect>
          <Line />
        </li>
      ))}
    </Ul>
  );
}
