inherit NPC;
void create()
{
   set_name("������",({"liang ziweng"}));
   set("gender","����");
   set("mingwang",-5000);
   set("combat_exp",260000);
   set("title","���ײο�");
   
   set("age",64);
   set("qi",880);
   set("max_qi",880);
   set("food",250);
   set("water",250);
   set("neili",800);
   set("max_neili",800);
   set("force_factor",40);

   set_skill("dodge",90);
   set_skill("force",90);
   set_skill("parry",90);
   set_skill("unarmed",90);
   set_skill("spear",90);
   set_skill("sword",90);
   

   setup();
   add_money("silver",10);
carry_object(__DIR__"obj/changpao")->wear();
carry_object(__DIR__"obj/yaochu")->wield();
}
