// ����˫����


inherit NPC;

void create()
{
  set_name("����", ({"tu fei","fei"}));
  set("long","����һ�����ˡ�\n");
  set("gender", "����");
  set("combat_exp",200000);

  set_skill("unarmed", 110);
  set_skill("dodge", 140);
  set_skill("parry", 130);
  
  setup();
  carry_object(__DIR__"obj/cloth")->wear();
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
     command("say �ܾ�û���������ˣ�˭���ǽ������˵ĵ�һ���أ�");
     break;
    case 1:
     command("say �⼸�����̫�����һ�����Ъ�Űɣ�");
   }
   
}

