// ����˫����


inherit NPC;

void create()
{
  set_name("������", ({"wang gongzi","wang","gongzi"}));
  set("long","����һλ��ѧ���ʵĹ��ӡ�\n");
  set("gender", "����");
  set("combat_exp", 30000);

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
     command("say ��ƪ�������в�ͬ�Ŀ�����˭�����ҽ���һ�£�");
     break;
    case 1:
     command("say �������лƽ��ݣ���仰��һ��Ҳ���ġ�");
   }
   
}

