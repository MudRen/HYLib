inherit NPC;
void create()
{
   set_name("С����",({"xiao guizi"}));
	set("gender", "����");
   set("age",14);
   set("combat_exp",200);
   
   set_skill("unarmed",5);
   set_skill("parry",5);
   set_skill("dodge",5);
   set("chat_chance",5);
   set("chat_msg",({
 "С���ӵ�:����̫���,�Դ�������.\n",
 "С���ӵ�:Ҫ������ϵ�,ס�����ӵ�,���ҵ�̫������.\n",
 "С���ӵ�:����̫��,���ž͹ܲ�����,�ж��.\n",
 "С���ӵ�:�����ȥ�Ķ���.\n",
 "С���ӵ�:Ҫ������һ�����Ӿͺ���.\n",
 }));
   set("inquiry",([
   "����":"���ʺ���������.\n",
   "̫��":"���ʺ���������.\n",
   ]));
 setup();
 add_money("silver",1);
 }

 int accept_object(object me, object obj)
{
	object pai;
        if( (string) obj->query("name") == "����"
        || obj->query("id") =="shai zi")
	{
        message_vision("$N��$nЦ��Ц��\n",this_object(),me);
        command("cool");
	command("say ���˽��ң��Ҿ���Ҫ�����\n");
	command("say �Ȿ42�¾����͸����ˣ�\n");
	pai = new("/d/city2/obj/book14_5");
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
