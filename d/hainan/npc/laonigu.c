#include <ansi.h>
inherit NPC;
string *name=({"������","������",});
void create()
{
 set_name(YEL+name[random(sizeof(name))]+NOR, ({ "nigu", "dashi" }) );
  set("gender", "Ů��");
  set("age", 40+random(40));
  set("title",YEL"�����ִ���"NOR);
  set("long","һλ���ݴ��������,������ɨ��ɨ�ء�\n");
  create_family("������",4,"����");
  set("attitude", "friendly");
  set("combat_exp", 1500000);
  set("per", 15);
  set_skill("parry", 180);
  set_skill("unarmed", 180);
  set_skill("dodge", 180);
  set_skill("sword", 180);
  set_skill("force", 180);
	set_temp("apply/attack",220);
	set_temp("apply/defense",220);
	set_temp("apply/armor",220);
	set("max_neili",500+random(5550));
	set("max_jing",500+random(5550));
		set("max_qi",500+random(5550));	

  set("max_sen",400);
  set("max_gee",400);
  set("max_gin",400);
  set("force",400);
  set("max_force",400);
  set("force_factor",3);
  setup();
  carry_object("/d/hainan/obj/hui_cloth")->wear();
  carry_object("/d/hainan/obj/saozhou")->wield();
   add_money("gold",1);
}
