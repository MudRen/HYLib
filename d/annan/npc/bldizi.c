inherit NPC;

void create()
{
   set_name("���ϰ����",({ "dizi"}) );
        set("gender", "����" );
        set("age",30+random(10));
   set("long", "���ǰ��ϰ�ĵ��ӡ���˵���ϰ��Է����˿�Ϊ����\n"+
               "���Թ��︾�˶�ԶԶ�ض������ǡ�\n");       
   set("combat_exp", 50000);
   set_skill("parry",50);
   set_skill("dodge",50);
   set_skill("force",50);
   set_skill("unarmed",50);
   set_skill("cuff",50);

   set("attitude", "peaceful");
   set("chat_chance",20);
   set("chat_msg",({
       (:random_move:),
   }));
   set("max_kee",100);
   set("target",1);
   add_money("coin",50);
   setup();
 
}

void init()
{
   object ob;
   ob=previous_object();
   if(userp(ob)&&!ob->is_fighting()&&living(ob))
    call_out("welcome",0,ob);
}

void welcome(object ob)
{
   if(!ob||!living(ob)||
   environment(ob)!=environment(this_object()))
   return;
   if(ob->query("gender")=="Ů��"){
     if(ob->query("class")=="bonze")
       message_vision("$N��$n�����˼���:ԭ���Ǹ���ã����ǵ�ù����\n",
           this_object(),ob);
     else
     message_vision("$N��$n�������´����ţ���֪���ڴ���ʲô�����⡣\n",
           this_object(),ob);}
   else
    message_vision("$N����ؿ��˿�$n",this_object(),ob);
    
   return;
}

