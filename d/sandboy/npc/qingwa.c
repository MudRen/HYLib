// yetu.c Ұ��

#include <ansi.h>
inherit NPC;

void create()
{
	set_name(HIB"����"NOR, ({ "frog", "qingwa", "wa" }) );
	set("race", "Ұ��");
	set("age", 5);
	set("long", "������ï�ܲݴ�������,ǳ��ɫ��������
�����ӻ�ɫ��������\n");
	set("attitude", "peaceful");
	
	set("limbs", ({ "ͷ��", "����", "ǰ��", "���", "��ͷ" }) );
	set("verbs", ({ "bite", "claw" }) );

	set("combat_exp", 500);

	set("chat_chance", 20);
	set("chat_msg", ({
		(:random_move:),
              HIB"����"NOR+"����װ׵Ķ���,���ɵغ�������.\n",
              HIB"����"NOR+"�����������ͷ,���ٵ�һմ,�Ѳ�Ҷ�ϵ�һֻ�ɶ��������.\n",
              HIB"����"NOR+"������һ������,���˻��,գ������.\n",
              HIB"����"NOR+"����һ��,�ڿ��л���һ�������Ļ���,�����Աߵ�ˮ��.\n",
	}) );
	
	set_temp("apply/attack", 2);
	set_temp("apply/defense", 5);
	set_temp("apply/damage", 2);
	set_temp("apply/armor", 1);

	setup();
}
