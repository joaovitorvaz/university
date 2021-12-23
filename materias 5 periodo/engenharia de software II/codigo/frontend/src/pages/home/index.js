/* eslint-disable jsx-a11y/anchor-is-valid */
import React from 'react';
import {ContainerHome, CardsSection} from "./styles";
import Search from '../../components/search';
import GameCard from "../../components/gameCard";

import data from './data';

export default function Home() {
  return (
    <ContainerHome>
      <Search placeholder="Busca" size="60%" />
      <CardsSection>
        {data.map((item) => (
          <GameCard key={item.id} to='/gamerent' game={item} extraInfo={item.price} tag="Disponível" />
        ))}
      </CardsSection>
    </ContainerHome>
  );

}