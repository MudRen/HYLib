inherit NPC;
void create()
{
   set_name("����",({"mingzhu"}));
   set("gender","����");
   set("age",45);
   set("combat_exp",10000);
   set("mingwang",4000);
   
   set_skill("unarmed",20);
   set_skill("parry",20);
   set_skill("dodge",20);
   set_skill("literate",50);
  set("chat_chance",5);
  set("chat_msg",({
  "�����:ƽ������Ȼ���췴,�ҿ��ǲ������.\n",
  "�����:�������µ�Τ��ͳץס�˰���,�ֹ��ڿ�������.\n",
  "�����:̫���Ǳ������г��̿���,���ܾ��ò����.\n",
  "�����:ǰ�������˽�������������Ǹ��ö�����\n",
  "�����:��Ҫ������ôһ�������ͺ���....\n",
  }));
   
   setup();
   add_money("silver",10);
}
 int accept_object(object me, object obj)
{
	object pai;
        if( (string) obj->query("name") == "�����"
        || obj->query("id") =="xiyang biao")
	{
        message_vision("$N��$n���˵�ͷ��\n",this_object(),me);
        command("thank");
	command("say �����������̫ϲ���ˣ�\n");
	command("say �Ȿ42�¾����͸���ɣ�\n");
	pai = new("/d/city2/obj/book14_8");
	if(pai)
	pai->move(me);
        message_vision("$N�ó�һ��42�¾�����$n��\n",this_object(),me);
        call_out("destroying", 0, obj,me);                       
	return 1;	
	}
else       return 0;
}

void destroying(object obj, object ob, object me)
{   

   if(obj) destruct(obj);
}
