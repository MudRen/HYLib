
inherit NPC;

void create()
{
   set_name("����",({ "dao ke","dao","ke"}) );
   set("gender", "����" );
   set("age", 20);
   set("long", "����һ�����͡�\n");       
   set("combat_exp",100000);
  
   set("chat_chance",30);
   
   set_skill("parry",100);
   set_skill("dodge",100);
   set_skill("force",100);
   set_skill("blade",100);
   set("chat_msg",({
     "���ͳ�������˼��Σ����˸���ʽ��\n",
     "��������һЦ��˵��������û׼����Ҳ�ܳ�Ϊ�õ��ĸ��֣�\n",
   }));
   setup();
   
   carry_object(__DIR__"obj/blade")->wield();
   
}

