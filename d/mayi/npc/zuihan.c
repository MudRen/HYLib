
inherit NPC;
void create()
{
   
   set_name("��",({ "zui han","zui","han"}) );
   set("gender", "����" );
   set("age",40+random(10));
   set("long", "����һ���ȵ���ѬѬ������\n");
   set("combat_exp", 100000);
   set("str", 30); 
   set("chat_chance",20);
   set("chat_msg",({
     "���ߵ���С���ã�ȥ�������������... ...\n",
     "����������˸��ӣ����������ȥ����������һ���ǧ�𣡣�\n",
     "�����������ף������أ����ֺ����ˣ�\n",
    }));    
   setup();
    carry_object("/clone/misc/cloth")->wear();
  
  
}

string long()
{
  command("say ��ʲô����������С����������һ�٣�����");
  return query("long");
  
}
  
