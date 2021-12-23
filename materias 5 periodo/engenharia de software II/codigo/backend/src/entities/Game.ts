import {
  Column,
  CreateDateColumn,
  Entity,
  JoinColumn,
  JoinTable,
  ManyToMany,
  PrimaryColumn,
  UpdateDateColumn,
} from "typeorm";
import { v4 as uuid } from "uuid";
import { User } from "./User";

@Entity("games")
export class Game {
  @PrimaryColumn()
  readonly id: string;

  @Column()
  name: string;

  @Column()
  genre: string;

  @Column()
  ageRestriction: number;

  @Column()
  price: number;

  @Column()
  platform: string;

  @Column()
  description: string;

  @Column()
  logo: string;

  @CreateDateColumn()
  created_at: Date;

  @UpdateDateColumn()
  updated_at: Date;

  constructor() {
    if (!this.id) {
      this.id = uuid();
    }
  }
}
