
inherit NPC;
void create()
{
   
   set_name("����",({ "lao zhe","lao","zhe"}) );
   set("gender", "����" );
   set("age",60+random(10));
   set("long", "����һλ���ߡ�\n");
   set("combat_exp", 1000);
   set("str", 30); 
   set("chat_chance",20);
   set("chat_msg",({
     "���߿޵����ҵ��������Ӷ�����ȥ�����ˣ�Ҳ��֪�������ǻ\n",
     "���߷ߵ�������ͻ���˺�����ˣ�������Ҳ����Ź�ͻ���ˣ���\n",
     "����̾������֪���һ��ܲ��ܼ���̫ƽʢ����\n",
     (:random_move:),
    }));    
   setup();
  
  
}

  