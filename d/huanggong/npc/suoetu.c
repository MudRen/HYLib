inherit NPC;
void create()
{
   set_name("����ͼ",({"suo etu"}));
   set("gender","����");
   set("age",45);
   set("combat_exp",2000);
   set("mingwang",4000);
   
   set_skill("unarmed",20);
   set_skill("parry",20);
   set_skill("dodge",20);
   set_skill("literate",50);
   set("chat_chance",4);
   set("chat_msg",({
  "����ͼ��:�������,����ô��ƽ��������?\n",
  "����ͼ��:������˻���ʶ��,�����������.\n",
  "����ͼ��:���϶����غ��ɹŵ��������������.\n",
  "����ͼ��:Ǯ�Ǻö�����!\n",
  "����ͼ��:���⹬����ʲô�¶��ٲ���Ǯ!\n",
  }));
   
   setup();
   add_money("silver",10);
}
int accept_object(object me, object obj)
{
	object pai;
        if( obj->query("money_id") && (int) obj->value() >= (10+ random(50)) * 10000)
	{
        message_vision("$N��$n�۵�һ��!��\n",this_object(),me);
        command("wa");
	command("say �ö���������ϲ�������ˣ�̫лл���ˣ�������㣡\n");
	pai = new("/d/city2/obj/book14_3");
	if(pai)
	pai->move(me);
        message_vision("$N�ó�һ��42�¾���$n��\n",this_object(),me);
	return 1;	
	}
else return 0;
}
