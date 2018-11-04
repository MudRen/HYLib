// zhao.c
#include <ansi.h>
inherit NPC;

void create()
{
	set_name("�԰�ɽ", ({"zhao banshan", "zhao", "banshan"}));
	set("title", HIR"�컨��"HIG"������"NOR);
	set("nickname", HIY "ǧ������" NOR );
	set("gender", "����");
	set("age", 48);
	set("long", 
"��һ�����ֵ�����Ц��������һ���ܴ���ĸо�����
ԭ����������̫�������Ŵ���ӡ�������������
����һ�ְ��������̫����������ƥ�С����������
��ɢ֮��Ͷ��컨�ᡣ�ܵñ��컨���ϵ�������ͤ
��ʶ��\n");
	set("attitude", "peaceful");
	set("class", "fighter");
	set("per", 21);
	set("str", 21);
	set("int", 30);
	set("con", 26);
	set("dex", 30);

	set("qi", 7500);
	set("max_qi", 7500);
	set("jing", 1000);
	set("max_jing", 1000);
	set("neili", 12500);
	set("max_neili", 12500);
	set("jiali", 100);
	set("combat_exp", 1000000);

	set_skill("force", 190);
	set_skill("taiji-shengong", 190);
	set_skill("unarmed", 190);
	set_skill("taiji-quan", 190);
	set_skill("throwing", 200);
	set_skill("hanxing-bada", 190);
	set_skill("dodge", 190);
	set_skill("tiyunzong", 190);
	set_skill("mantian-xing", 290);
	set_skill("parry", 190);
	set_skill("sword", 190);
	set_skill("taiji-jian", 190);

	map_skill("force"  , "taiji-shengong");
	map_skill("unarmed", "taiji-quan");
	map_skill("dodge"  , "tiyunzong");
	map_skill("parry"  , "taiji-jian");
	map_skill("sword"  , "taiji-jian");
	map_skill("throwing"  , "hanxing-bada");
	set("chat_chance_combat", 70);  
	set("chat_msg_combat", ({
		(: command("wield changjian") :),
		(: command("haha") :),
		(: command("unwield changjian") :),
		(: command("wield jili") :),
		(: command("unwield jili") :),
	}));
	setup();
	
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/weapon/jili")->wield();
	carry_object("/clone/cloth/cloth")->wear();
}
