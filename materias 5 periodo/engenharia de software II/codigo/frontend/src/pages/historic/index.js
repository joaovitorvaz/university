/* eslint-disable jsx-a11y/anchor-is-valid */
import React from 'react';
import {InitialSection, ContainerHistoric, CardsSection} from "./styles";
import Search from '../../components/search';
import GameCard from "../../components/gameCard";

import RuneTerra from '../../assets/games/runeterra.png';
import DarkSouls from '../../assets/games/DarkSouls3.png';

export default function Historic() {

  let rune = {
    name: "Legends of RuneTerra",
    short: "RuneTerra",
    info: "Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged.",
    image: RuneTerra,
    genre: "Ação",
    classification: "LIVRE",
    platform: "PC",
    price: "250,00"
  };

  let dark = {
    name: "Dark Souls 3",
    short: "DS3",
    info: "Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged.",
    image: DarkSouls,
    genre: "Ação",
    classification: "16",
    platform: "PC",
    price: "199,90"
  };

  return (
    <ContainerHistoric>
      <InitialSection>
        <h1>Histórico</h1>
        <Search placeholder="Busca" size="100%" />
      </InitialSection>      
      <CardsSection>
        <GameCard to='/gamerent' game={rune} extraInfo="04/08/2021" tag="Alugado" />
        <GameCard to='/gamerent' game={dark} extraInfo="04/08/2021" tag="Expirado" />
      </CardsSection>
    </ContainerHistoric>
  );

}