inherit NPC;
void create()
{
   set_name("���պ���",({"wangye","wanyan"}));
   set("gender","����");
   set("long","���������.\n");
   set("mingwang",-10000);
   set("combat_exp",16000);
set("title","����ү");
   
   set("age",45);
   set("qi",680);
   set("max_qi",680);
   set("food",250);
   set("water",250);
   set("neili",300);
   set("max_neili",300);
   set("force_factor",20);

   set_skill("dodge",60);
   set_skill("force",60);
   set_skill("parry",60);
   set_skill("unarmed",60);
   set_skill("club",60);
   set_skill("sword",60);

   setup();
   add_money("gold",1);
carry_object(__DIR__"obj/jinpao")->wear();
}
