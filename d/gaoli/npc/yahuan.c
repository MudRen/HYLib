// ����˫����

inherit NPC;

void create()
{
  set_name("Ѿ��", ({"ya huan","huan"}));
  set("long","����һλѾ�ߡ�\n");
  set("gender", "Ů��");
  set("combat_exp", 3000);
  set("age", 18);
  set("per", 23);
  set("attitude", "friendly");
  set_skill("unarmed", 10);
  set_skill("dodge", 40);
  set_skill("parry", 30);
 
  setup();
  carry_object("/d/gaoli/obj/cloth")->wear();
}

void init()
{
   object ob;
   
   ob=this_player();
   
   if(!ob||is_fighting()) return;
   
   remove_call_out("welcome");
   call_out("welcome",1,ob);
   
}

void welcome(object ob)
{
   if(!ob) return;
   if(environment(ob)!=environment(this_object()))
   return;
   
   switch(random(2)){
    case 0:
     command("say ū�����������ˣ�");
     break;
    case 1:
     command("say ��˵��үҪ��������С檣���֪�������Ǽ١�");
   }
   
}


