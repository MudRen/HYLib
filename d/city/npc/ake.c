// ake.c

#include <ansi.h>
inherit NPC;
inherit F_DEALER;

void create()
{
	set_name("����", ({ "a ke", "ke" }) );
	set("gender", "Ů��" );
	set("long", "����Ϊ���Գ����ԲԲ֮Ů��
����ɫ�������ھ������������ָϸ�����ۣ������ð����
�ɣ��ֱ�����ָ�����������СС��Բ�С�
����ΤС��һ������Ů������ʮ�����꣬�ؿ����类һ����
�ε��������ػ���һ�ǣ���ʱ֮�䴽����ɣ�Ŀ�ɿڴ�����
�����������ˣ������ˣ�����������������Ů������Ů����
�����������ţ�С�ʵ۸��һ�λҲ���ɡ�ΤС����Ƥ���
�����µأ�ǹ�ּ��꣬��ɽ�͹���������������Ȣ�������
�����Ų��ɡ���\n");
	set("age", 16);
	set("combat_exp", 50000);
	set("attitude", "friendly");
	set("per",30);
	set("no_get", 1);
	set("no_get_from", 1);
	set_skill("unarmed", 40);
	set_skill("dodge", 40);
	setup();

	carry_object(__DIR__"obj/flower_shoe")->wear();
	carry_object(__DIR__"obj/green_cloth")->wear();
}

void init()
{
	add_action("do_value", "value");
	add_action("do_pawn", "pawn");
//	add_action("do_redeem", "redeem");
}


