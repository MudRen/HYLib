// Feb. 6, 1999 by Winder
#include <ansi.h>
inherit NPC;
void create()
{
	set_name("�·���", ({ "wen fangwu", "wen" }) );
	set("gender", "����");
        set("title", "�¼��ϴ�");
	set("age", 45);
	set("long",
		"��λ�����¼��϶����·���\n");
	set("combat_exp", 1000000);
        set("shen_type", 1);
	set("attitude", "heroism");
	set("str", 30);
	set("con", 25);
	set("int", 20);
	set("dex", 30);
	set("max_qi", 5000);
	set("eff_qi", 5000);
	set("qi", 5000);
	set("max_jing", 2000);
	set("jing", 2000);
	set("neili", 5000);
	set("max_neili", 5000);
	set("jiali", 30);
	set("shen_type", 0);
        set("chat_chance", 15);
	set("inquiry", ([
		"�����ɾ�" : "��ѩ���������������һ��Ҫ������ʬ��ϣ�" ,
		"����"   : "���СѾͷ����а�ˣ����ҹ�����������Ҳ��Ϊ���ð���",
	]) );
	set_temp("apply/attack",  250);
	set_temp("apply/defense", 250);
	set_skill("sword", 300);
	set_skill("unarmed", 380);
	set_skill("parry", 300);
	set_skill("dodge", 300);
	setup();
        carry_object("/d/city/obj/gangjian")->wield();
        carry_object("/d/city/obj/tiejia")->wear();
}
