#include <ansi.h>

inherit NPC;

void create()
{
  set_name("����",({ "meng yun", "dizi","girl" }) );
  set("gender", "Ů��" );
  set("title",YEL+"�۽��"+NOR);
  set("long", "�����ֵ���֮һ,ר�ſ�����Щ͵������.\n");
  set("age", 15+random(10));
  set("attitude", "peaceful");
  set("str", 50);
  set("per", 50);
  set("combat_exp",340000);
  set("force",500);
  set("max_force",500);
  set("force_factor", 100);
  set("max_gin", 400);
  set("max_kee", 400);
  set("max_sen", 400);
  set("inquiry",([
  "��ȥ":"Ҫ���ȥ,�ȹ��������.\n",
  ]));
  set_skill("unarmed",150);
  set_skill("dodge",150);
  set_skill("parry",150);
  set_skill("whip",150);
  set_skill("force",150);
	set_temp("apply/attack",220);
	set_temp("apply/defense",220);
	set_temp("apply/armor",220);
	set("max_neili",500+random(5550));
	set("max_jing",500+random(5550));
		set("max_qi",500+random(5550));	

  
  set("chat_chance",6);
  set("chat_msg",({
  "����˵��:�������Щ������å��.\n",
  "���ƺٺ�һЦ,��������,���ȥ������.\n",
  "���Ƶ�:Ҫ���ȥ,���ȹ��������.\n",
}));

  setup();
  carry_object("/d/hainan/obj/triger_cloth")->wear();
  carry_object("/d/hainan/obj/whip")->wield();
}
