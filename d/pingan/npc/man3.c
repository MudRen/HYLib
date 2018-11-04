#include <ansi.h>

inherit NPC;

mapping *data=({
(["name":"������",	"id":"han",		"mw":1,	]),
(["name":"����",	"id":"biesan",	"mw":-1,	]),
(["name":"��ͷ",	"id":"bu tou",	"mw":1,	"weapon":"blade",	]),
(["name":"ǿ��",	"id":"ren",		"mw":-1,	"weapon":"blade",	]),
(["name":"����ɮ��","id":"seng",		"mw":1,	"weapon":"club",	]),
(["name":"���ֶ�ɮ","id":"seng",		"mw":-1,	"weapon":"club",	]),
(["name":"��ʿ",	"id":"wushi",		"mw":1,	"weapon":"sword",	]),
(["name":"ǿ��ͷ",	"id":"qiang dao",	"mw":-1,	"weapon":"hammer",]),
(["name":"����ɮ",	"id":"seng",		"mw":1,	"weapon":"blade",	]),
(["name":"��ɮ",	"id":"seng",		"mw":-1,	"weapon":"sword",]),
(["name":"��������","id":"shiwei",	"mw":1,	"weapon":"blade",	]),
(["name":"ɽ��",	"id":"sanzei",	"mw":-1,	"weapon":"throwing",]),
});


void create()
{
	mapping npc;
	string weapon;
	npc=data[random(sizeof(data))];
	weapon=npc["weapon"];

	set_name(HIR+npc["name"]+NOR,({ npc["id"] }));
	set("age",20+random(30));
	set("combat_exp",50000+random(50000));
	set_temp("apply/attack",90);
	set_temp("apply/defense",90);
	set_temp("apply/armor",50);
	set("max_force",1000);
	if( weapon)	set_skill(weapon,60);
	set_skill("unarmed",60);
	set_skill("parry",60);
	set_skill("dodge",60);
	set("shen_type",npc["mw"]);
	setup();
	carry_object("/clone/cloth/cloth")->wear();
        set("chat_chance", 10);
        set("chat_msg", ({
                (: random_move :),
        }) );
	if( weapon)
//		carry_object("/clone/weapon/"+weapon)->wield();
	add_money("silver",20+random(20));
}
       
