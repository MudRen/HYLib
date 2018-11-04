#include <ansi.h>

inherit NPC;

mapping *data=({
(["name":"����Ԫ��",	"id":"yuanlao",	"mw":-1,	]),
(["name":"���½̳���",	"id":"zhanglao",	"mw":1,	]),
(["name":"���ߵ�����",	"id":"daozhu",	"mw":-1,	"weapon":"gangdao",	]),
(["name":"ؤ�ﳤ��",	"id":"zhanglao",	"mw":1,	"weapon":"changqiang",	]),
(["name":"���»�᳤",	"id":"huizhang",	"mw":1,	"weapon":"gangdao",	]),
(["name":"��ɽ������",	"id":"yinzhe",	"mw":-1,	"weapon":"gangjian",	]),
(["name":"��ǰ������",	"id":"zhang",		"mw":1,	"weapon":"gangjian",	]),
(["name":"������ʦ",	"id":"chanshi",	"mw":1,	"weapon":"gangdao",]),
(["name":"���չ�����",	"id":"zhanglao",	"mw":-1,	"weapon":"changbian",	]),
(["name":"ɽ����",		"id":"daiwang",	"mw":-1,	"weapon":"lianzi",]),
(["name":"������ϴ�",	"id":"laoda",		"mw":-1,	"weapon":"hammer",	]),
(["name":"����ɽ����",	"id":"zhangmen",	"mw":1,	"weapon":"gangjian",]),
});


void create()
{
	mapping npc;
	string weapon;
	npc=data[random(sizeof(data))];
	weapon=npc["weapon"];

	set_name(HIM+npc["name"]+NOR,({ npc["id"] }));
	set("age",20+random(30));
	set("combat_exp",1000000+random(1000000));
	set_temp("apply/attack",250);
	set_temp("apply/defense",250);
	set_temp("apply/armor",90);
	set("max_force",2000);
	if( weapon)	set_skill("blade",200);
	set_skill("unarmed",200);
	set_skill("sword",200);
	set_skill("club",200);
	set_skill("whip",200);
	set_skill("throwing",200);
	set_skill("parry",200);
	set_skill("dodge",200);
	set("shen_type",npc["mw"]);
        set("chat_chance", 1);
        set("chat_msg", ({
                (: random_move :),
        }) );
	setup();
	carry_object("/clone/cloth/cloth")->wear();
	if( weapon)
		carry_object("/clone/weapon/"+weapon)->wield();
	add_money("silver",50+random(50));
}
       
