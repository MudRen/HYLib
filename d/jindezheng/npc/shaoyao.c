inherit NPC;
void create()
{
      set_name("��Ҥ��",({"gongren","worker"}));
      set("gender","����");
      set("age",20+random(40));
      set("shen_type",1);
      set("combat_exp",30000+random(40000));
      set("str",40);
      set("per",16);
      set_skill("unarmed",15);
      set_skill("parry",15);
      set_skill("dodge",15);
      setup();
      carry_object("/clone/misc/cloth")->wear();
      add_money("silver",10);
 }