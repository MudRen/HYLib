inherit NPC;

void create()
{
   set_name("Ů��",({ "nv xia","nv","xia" }) );
        set("gender", "Ů��" );
        set("age",20+random(10));
   set("long", "����һ������������Ů����������Ӣ���ˬ��\n");       
   set("combat_exp",150000);
   set("str",22);
   set_skill("parry",110);
   set_skill("unarmed",110);
   set_skill("dodge",110);
   set_skill("sword",210);

  set("attitude", "peaceful");
   
   setup();
   carry_object(__DIR__"obj/duanjian")->wield();
   carry_object(__DIR__"obj/erhuan")->wear();
  
}
void init()
{
  object ob;
  ob=previous_object();
  if(userp(ob)&&!ob->is_fighting()&&living(ob))
   call_out("welcome",0,ob);
}

void welcome(object ob)
{
  if(!ob||!living(ob)||ob->is_fighting())
  return;
  switch(random(5)){
  case 0:command("sigh");break;
  case 1:command("poor");break;
  case 2:command("hi");break;
  case 3:command("welcome");break;
  case 4:command("dtsl");break;}
  return;
}
  