inherit NPC;
void create()
{
   set_name("���",({"rui chu"}));
   set("age","Ů��");
   set("nickname","С��Ů");
   set("age",15);
   set("combat_exp",200);
   
   set_skill("unarmed",5);
   set("chat_chance",5);
   set("chat_msg",({
   "�����:���캣������ҹ����������,�ҿ�û����.\n",
   "�����:��ǰС���ӳ���������.\n",
   "�����:����˵�����Ƥ��Ϻ�ر�óԣ������һ��.\n",
   "�����:�ϴ��ڱ����Թ�һ���Ƥ��Ϻ,��Ҳ������.\n",
   }));
   setup();
   carry_object("/clone/cloth/female5-cloth.c")->wear();
}
 int accept_object(object me, object obj)
{
	object pai;
        if( (string) obj->query("name") == "��Ƥ��Ϻ"
        || obj->query("id") =="cp dx")
	{
        message_vision("$N��$nЦ��Ц��\n",this_object(),me);
        command("love");
	command("say ̫лл���ˣ��Ҿ���ϲ���������\n");
	command("say �Ȿ42�¾������͸���ɣ�\n");
	pai = new("/d/city2/obj/book14_6");
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
