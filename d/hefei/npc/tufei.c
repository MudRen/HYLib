
inherit NPC;

void create()
{
   set_name("����",({ "tu fei","fei"}) );
        set("gender", "����" );
        set("age",30);
   set("long", "����һλ��������Ŀ¶�׹�����ˡ�\n");       
   set("combat_exp",100000);
   set("str", 10);
   set_skill("dodge",100);
   set_skill("parry",100);
   set_skill("cuff",100);
   set("chat_chance",30);
   set("chat_msg",({
     "�����૵�������ͷ����Ǯ��Խ��Խ���ˣ�׬��Ǯ�治���װ���\n",
     "���˶�ݺݵ�˵������������ǰ���ң����Ĵ�ү�Ҷ����㣡\n",
     "���˿�����һ��˵���������ҵ����鲻����������ȥ�ɡ�\n",
     }));
   setup();
   add_money("silver",2);
}

