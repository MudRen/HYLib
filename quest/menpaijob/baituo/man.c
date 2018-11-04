#include <ansi.h>
int do_walk();
inherit NPC;
mapping *data=({
(["name":"�佫",	"id":"wu jiang",	"mw":-1,	]),
(["name":"ɽ��ͷ",	"id":"shan zeitou",	"mw":1,	]),
(["name":"�͵���",	"id":"huo ji",	"mw":-1,	"weapon":"gangdao",	]),
(["name":"����",	"id":"shi wei",	"mw":1,	"weapon":"changqiang",	]),
(["name":"����",	"id":"tie jiang",	"mw":1,	"weapon":"gangdao",	]),
(["name":"��åͷ",	"id":"liumang tou",	"mw":-1,	"weapon":"gangjian",	]),
(["name":"����",	"id":"gui gongzi",		"mw":1,	"weapon":"gangjian",	]),
(["name":"����",	"id":"xing ze",	"mw":1,	"weapon":"gangdao",]),
(["name":"����ͷ",	"id":"tufei tou",	"mw":-1,	"weapon":"changbian",	]),
(["name":"Ϸ��",		"id":"xi zi",	"mw":-1,	"weapon":"lianzi",]),
(["name":"̨���̷�",	"id":"shang fan",		"mw":-1,	"weapon":"hammer",	]),
(["name":"��������",	"id":"yi ren",	"mw":1,	"weapon":"gangjian",]),
(["name":"������",	"id":"kanzu ren",	"mw":-1,	"weapon":"changbian",	]),
(["name":"����",		"id":"lie ren",	"mw":-1,	"weapon":"lianzi",]),
(["name":"̨������",	"id":"old lieren",		"mw":-1,	"weapon":"hammer",	]),
(["name":"������",	"id":"muyang ren",	"mw":1,	"weapon":"gangjian",]),
(["name":"ũ��",	"id":"nong fu",	"mw":1,	"weapon":"gangjian",]),
(["name":"Ƥ����",	"id":"pihuo sang",	"mw":-1,	"weapon":"changbian",	]),
(["name":"ʯ��",		"id":"shi jiang",	"mw":-1,	"weapon":"lianzi",]),
(["name":"����",	"id":"dao ren",		"mw":-1,	"weapon":"hammer",	]),
(["name":"�ο�",	"id":"you ke",	"mw":1,	"weapon":"gangjian",]),
(["name":"��ͯ",	"id":"shu tong",	"mw":1,	"weapon":"gangjian",]),
(["name":"��Ӫ����",	"id":"guan bing",	"mw":-1,	"weapon":"changbian",	]),
(["name":"Ա��",		"id":"yuan wai",	"mw":-1,	"weapon":"lianzi",]),
(["name":"����",	"id":"bi qiu",		"mw":-1,	"weapon":"hammer",	]),
(["name":"��å",	"id":"liu mang",	"mw":1,	"weapon":"gangjian",]),
});


void create()
{
	mapping npc;
	string weapon;
	npc=data[random(sizeof(data))];
	weapon=npc["weapon"];

	set_name(npc["name"],({ npc["id"] }));
	set("age",20+random(30));
		set("gender", "����");
	set("combat_exp",20000);
	if( weapon)	set_skill("blade",20);
	set_skill("unarmed",20);
        set("tasknpc",1);
        set("dex",100);
        set("no_get",1);
	set_skill("sword",20);
	set_skill("club",20);
	set_skill("whip",20);
	set_skill("throwing",20);
	set_skill("parry",20);
	set_skill("dodge",20);
	set("shen_type",npc["mw"]);

        set_temp("apply/attack", 20);
        set_temp("apply/defense", 20);
        set_temp("apply/armor", 20);
        set_temp("apply/damage", 20);

        setup();
        set("check_time", time());
	carry_object("/clone/cloth/cloth")->wear();
}
       
void init()
{       
        if( environment() && !is_fighting() ) {
                call_out("leave", 5);
                return;
        }
}
void leave()
{
if(!is_fighting())
{
        message("vision",HIB+name()+"����ææ���߿��ˡ�\n" NOR, 
                environment(), this_object() );
        destruct(this_object());
} else                 call_out("leave", 10);
}

void die()
{
        object ob, me, corpse;
        
        ob = this_object();
message_vision("$N��ž����һ�����ڵ��ϣ���������˿��Ѫ��ʹ��������˼��¾����ˡ�\n", ob);
        destruct(ob);
        return;
}