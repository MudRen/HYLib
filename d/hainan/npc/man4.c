#include <ansi.h>

inherit NPC;

mapping *data=({
(["name":"�ض���",	"id":"han",		"mw":1,	]),
(["name":"����ǿ��",	"id":"ren",	"mw":-1,	]),
(["name":"Ѳ��ͷ��",	"id":"touling",	"mw":1,	"weapon":"blade",	]),
(["name":"����ǿ��",	"id":"qiangdao",	"mw":-1,	"weapon":"blade",	]),
(["name":"����ɮ",		"id":"seng",		"mw":1,	"weapon":"club",	]),
(["name":"��ͷ��",		"id":"toutuo",	"mw":-1,	"weapon":"blade",	]),
(["name":"������",		"id":"wei",		"mw":-1,	"weapon":"sword",	]),
(["name":"��������",	"id":"shiwei",	"mw":-1,	"weapon":"whip",]),
(["name":"���ε�ʿ",	"id":"daoshi",	"mw":1,	"weapon":"sword",	]),
(["name":"����",		"id":"dao",		"mw":-1,	"weapon":"sword",]),
(["name":"�������",	"id":"guan",		"mw":1,	"weapon":"blade",	]),
(["name":"ɽ��ͷ",		"id":"dou",		"mw":-1,	"weapon":"hammer",]),
});


void create()
{
	mapping npc;
	string weapon;
	npc=data[random(sizeof(data))];
	weapon=npc["weapon"];

	set_name(npc["name"],({ npc["id"] }));
	set("age",20+random(30));
	set("combat_exp",250000+random(250000));
	set_temp("apply/attack",150);
	set_temp("apply/defense",150);
	set_temp("apply/armor",60);
	set("max_force",1200);
	if( weapon)	set_skill(weapon,100);
	set_skill("unarmed",100);
	set_skill("parry",100);
	set_skill("dodge",100);
	set_temp("apply/attack",120);
	set_temp("apply/defense",20);
	set_temp("apply/armor",120);
	set("max_neili",500+random(5550));
	set("max_jing",500+random(5550));
		set("max_qi",500+random(5550));	
        set("chat_chance", 20);
        set("chat_msg", ({
 (: random_move :)

        }) );		
	set("shen_type",npc["mw"]);
	setup();
	carry_object(__DIR__"weapon/cloth")->wear();
	if( weapon)
		carry_object(__DIR__"weapon/"+weapon)->wield();
	add_money("silver",30+random(30));
}
       
