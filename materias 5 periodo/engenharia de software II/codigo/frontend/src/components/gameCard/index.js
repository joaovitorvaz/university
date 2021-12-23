import React from 'react';
import {Card, Image, Info, Data, DataText, Tag, TagText} from "./styles";

export default function GameCard({ to, game, extraInfo, tag }) {
  return (
    <Card to={to} state={game}>
      <Image src={game.image} />
      <Info>
        <Data>
          <DataText>{game.short}</DataText>
          <DataText>{extraInfo}</DataText>
        </Data>
        <Tag>
          <TagText>{tag}</TagText>
        </Tag>
      </Info>
    </Card>
  );
}