
inherit NPC;
void create()
{
   
   set_name("����",({ "shu sheng","shu","sheng"}) );
   set("gender", "����" );
   set("age",20+random(10));
   set("long", "����һ��������������������Щ���ǡ�\n");
   set("combat_exp", 100000);
   set("str", 30); 
   set("chat_chance",20);
   set("chat_msg",({
     "��������̾����ʱ�����ң�����������ҵĲŻ���η��ӣ�\n",
     "����̾�˿��������޺�ƽʢ����������ǧ���������к��ã�\n",
     "����һ˦���ӣ��ߣ��Ҳ����ż����裬ȥ����ɱͻ���˺��ˣ�\n",
     (:random_move:),
    }));    
   setup();
    carry_object("/clone/misc/cloth")->wear();
  
  
}

  
