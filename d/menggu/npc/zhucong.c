inherit NPC;
void create()
{
   set_name("���",({"zhu cong"}));
   set("gender","����");
   set("long","�����߹��϶�,���Ϲ����˵�!\n");
   set("shen",80000);
   set("combat_exp",170000);
   set("title","��������");
   
set("per",30);
set("age",34);
   set("kee",1700);
   set("max_kee",1700);
set("food",250);
set("water",250);
   set("neili",1700);
   set("max_neili",1700);
   set("force_factor",20);

   set_skill("dodge",170);
   set_skill("force",170);
   set_skill("parry",170);
   set_skill("unarmed",170);
   set_skill("sword",170);

   setup();
   add_money("silver",70);
carry_object(__DIR__"obj/cloth")->wear();
carry_object(__DIR__"obj/zheshan")->wield();
}
