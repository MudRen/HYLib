// dingtong.c
#include <ansi.h>
inherit NPC;
void create()
{
       set_name("陈达海", ({ "chen dahai", "chen", "dahai" }) );
       set("title", "镖师");
       set("nickname", "青蟒剑");
       set("gender", "男性" );
       set("shen", -2500);
       set("age", 43);
       set("str", 23);
       set("con", 20);
       set("int", 20);
       set("dex", 22);
       set("env/wimpy", 60);
       set("long","
一个身穿羊皮袄的高大汉子，虬髯满腮，说的哈萨克语很不纯正，
但目光炯炯，腰间挂著一柄长剑。他是霍元龙手下的镖师之一。\n" );
       set("combat_exp", 250000);
       set("attitude", "heroism");
        set("chat_chance", 10);
       set("chat_msg", ({ (: random_move :) }) );          
       set("max_qi", 600);
       set("max_jing", 500);
       set("neili", 700);
       set("max_neili", 700);
       set("jiali", 10);
       set_skill("force", 60); 
       set_skill("unarmed", 30);
       set_skill("sword", 60);
       set_skill("dodge", 60);
       set_skill("parry", 60);
       set_skill("qingmang-jian", 60); 
       map_skill("sword", "qingmang-jian");
       map_skill("parry", "qingmang-jian");
       map_skill("parry", "qingmang-jian");       
       setup();
       carry_object(__DIR__"obj/jinjian")->wield();
       carry_object("/clone/misc/cloth")->wear();
       add_money("silver", 10);
}
#include "bs.h";
