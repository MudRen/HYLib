#include <ansi.h>
inherit NPC;
void create()
{
  set_name("С��", ({ "xiao yi" , "yi" , "xiaoyi"}) );
  set("gender", "Ů��");
  set("age", 25);
  set("title",MAG"������"NOR);
  set("long","һ��������СѾͷ.\n");
  set("attitude", "friendly");
  set("combat_exp", 500000);
  set("per", 30);
  set("int",30);
  set_skill("parry", 100);
  set_skill("unarmed", 100);
  set_skill("dodge", 100);
  set_skill("sword", 100);
  set_skill("force", 100);
  set("max_sen",2000);
  set("max_gee",2000);
  set("max_gin",2000);
  set("force",5000);
  set("max_force",5000);
  set("force_factor",800);
  setup();
  carry_object("/d/hainan/obj/zishan")->wear();
  carry_object("/d/hainan/obj/shixuejian")->wield();
  add_money("gold",1);
}

