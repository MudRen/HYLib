inherit NPC;
void create()
{  
//   reload("gaoli_tiejiang");
   set_name("����",({ "tie jiang","tie","jiang","tiejiang" }) );
   set("gender", "����" );
   set("shop_id",({ "tie jiang","tie","jiang","tiejiang" }) );
   set("age", 40);
   set("long", "���Ǹ�����������������ı������Ǻܺá�\n");
   set("combat_exp",300000);
   set("str",26);
   set("neili",500);
   set("max_neili",500);
   set("kee",800);
   set("max_qi",800);
   set("sen",500);
   set("max_jing",500);
   set_skill("dodge",80);
   set_skill("parry",80);
   set_skill("unarmed",80);
   set("attitude", "peaceful");

  setup();
  carry_object("d/gaoli/obj/cloth")->wear();

 }

