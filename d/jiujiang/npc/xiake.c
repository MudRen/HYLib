
inherit NPC;

void create()
{
   set_name("����",({ "xia ke","xia","ke"}) );
        set("gender", "����" );
        set("age", 28);
   set("long", "����һ���������������͡�\n");
   set("combat_exp", 80000);
   set("str", 10);
   set("per", 24);
   set("max_neili",500);
   set("force",500);
   set("unarmed",80);
   set("dodge",80);
   set("parry",80);
   set("max_qi",500);
   set("max_jing",500);
   set("max_sen",500);
   set("attitude", "peaceful");
   setup();
   carry_object(__DIR__"obj/cloth")->wear();
  
}

