// ����˫����


inherit NPC;

void create()
{
  set_name("����", ({"gong zi","zi","gong"}));
  set("long","����һλ�������Ĺ��ӡ�\n");
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
     command("say �ҵ�����Ҳ��С�ˣ���֪��˭�ҵĹ���ϼ޸����أ�");
     break;
    case 1:
     command("say ƾ�ҵĲŻ���ȣ���һ��Ư���Ĺ��ﻹ��������׾١�");
   }
   
}

