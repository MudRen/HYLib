// ����˫����


inherit NPC;

void create()
{
  set_name("����", ({"jian ke","ke"}));
  set("long","����һ�������Ľ��͡�\n");
  set("gender", "����");
  set("combat_exp", 600000);

  set_skill("unarmed", 310);
  set_skill("dodge",320);
  set_skill("parry",320);
  set_skill("sword",320);
  set_skill("force",320);
  
  //set_skill("babu-ganchan",120);
  //set_skill("leveltwo-sword",120);
  
  setup();
  carry_object("/d/gaoli/obj/cloth")->wear();
  carry_object("/d/gaoli/obj/changjian")->wield();
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
     command("say �ҵĽ����Ǻ��Ľ���ѧ�ģ��ǳ��߳��ģ�");
     break;
    case 1:
     command("say �����Ҵ�ţ������ҵĽ����ڸ���Ҳ��һ�����ˡ�");
   }
   
}

