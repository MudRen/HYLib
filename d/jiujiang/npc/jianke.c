
inherit NPC;

void create()
{
   set_name("����",({ "jian ke","jian","ke" }) );
        set("gender", "����" );
        set("age", 32);
   set("long", "����һ����ͨ�Ľ��͡�\n");
       
   set("combat_exp",200000);
   set("attitude", "peaceful");
   set_skill("parry",80);
   set_skill("dodge",80);
   set_skill("force",80);
   set_skill("sword",80);

   setup();
   carry_object(__DIR__"sword")->wield();
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
   message_vision("$N��$n���˼��ۣ�Ȼ����������������ɱ�����������������ӣ�\n",this_object(),ob);
  else
   if(ob->query("class")=="bonze")
    message_vision("$N��$n���˼��ۣ��ְ�ͷת����һ�ߡ�\n",
     this_object(),ob);
   else
   message_vision("$N��$n�ڰ���:������"+RANK_D->query_respect(ob)+",�����������ˣ�һ������һ���ɣ�\n",
   this_object(),ob);
   return;
}
