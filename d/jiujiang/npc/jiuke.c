
inherit NPC;

void create()
{
   set_name("�ƿ�",({ "jiu ke","jiu","ke" }) );
        set("gender", "����" );
        set("age", 32);
   set("long", "����һ�������ڴ���¥�ȾƵ��ˣ���������Щ������ɣ�����ӡ�\n");
       
   set("combat_exp",30000);
   set("attitude", "peaceful");
   add_money("coin",30);
   setup();
  
}

void init()
{
   object ob;
   ob=previous_object();
   if(userp(ob)&&!ob->is_fighting()&&living(ob))
    call_out("welcome",1,ob);
   return;
}

void welcome(object ob)
{
  if(!ob||
  environment(this_object())!=environment(ob)
  ||!living(ob))
  return;
  if(ob->query_temp("dtsl_job_cisha/step2"))
   message_vision("$N��$n���˼��ۣ�Ȼ�����̾���������˸��������ġ�\n",this_object(),ob);
  else
   if(ob->query("class")=="bonze")
    message_vision("$N����$nһ�ۣ���Ȼ�������ҵģ��������ǵ�ù͸������\n",
     this_object(),ob);
   else
   message_vision("$N��$n�ڰ���:������"+RANK_D->query_respect(ob)+",һ������һ���ɣ�\n",
   this_object(),ob);
   return;
}
