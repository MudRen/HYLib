#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", "��ɽ");
	set("long", @LONG
��������Ů���ɽ��һ��Сɽ�ȣ������˼����������й������죬����ɭ
ɭ��ż����Զ�����������������������������㣬��ֱ���������Լ���
��������Դ��
������ԶԶ�Ŀ�������������С�ݣ����������Ѿ��þ�ÿס�����ˡ������ﲻ
���������������ô���أ�
LONG
	);
	set("exits", ([
		"northdown" : __DIR__"midong",
	]));
set("tbg",1);
	set("outdoors", "��ɽ" );

	setup();
}
void init()
{
  add_action("do_shout","han");
}


int do_shout(string arg)
{
    object ob,me;
    int j;
    me=this_player();
    if (!arg||arg!="����ǰ��")
      return notify_fail("����Ϲ���ҽ�Щʲô?\n");
// if( me->query("family/family_name") != "��ɽ��")
//{
//message_vision(HIY"�����ǻ�ɽ�ĵط������������޹ذɡ���\n"NOR,me);
//return notify_fail("����Ϲ���ҽ�Щʲô?\n");
//}
    if (me->is_busy())
      return notify_fail("����æ���أ����ܺ��С�\n");
    if (me->is_fighting())
      return notify_fail("�㻹��ר�Ĵ�ܰɡ�\n");
     message_vision(HIY"$N���õ���֮����������Х��:������ǰ����������\n"NOR,me);
     if(random(10)<6)   
{
     message_vision(HIY"��Ұ�ž�������Ψ�пչȻ������Ʈɢ����\n"NOR,me);
       return notify_fail("��Ұ�ž�������Ψ�пչȻ������Ʈɢ��\n");
}
     if(!query("tbg"))   
{
     message_vision(HIY"��Ұ�ž�������Ψ�пչȻ������Ʈɢ����\n"NOR,me);
message_vision(HIY"����ǰ�������ڼҡ���\n"NOR,me);
       return notify_fail("����ǰ�������ڼҡ�\n");
}

     ob=new(__DIR__"npc/tbg");
     ob->move(this_object());
     j=(int)me->query_skill("force") - 80;
        
       ob->set_skill("blade",j);
       ob->set_skill("parry",j);
       ob->set_skill("cuff",j);
       ob->set_skill("dodge",j);
       ob->set_skill("kuangfeng-blade",j);
       ob->set_skill("taizu-quan",j);
       ob->set_skill("force",j);
       ob->set_skill("huntian-qigong",j);
       ob->set_skill("shaolin-shenfa",j);
       
       ob->map_skill("dodge","shaolin-shenfa");
       ob->map_skill("blade","kuangfeng-blade");
       ob->map_skill("cuff","taizu-quan");
       ob->map_skill("parry","kuangfeng-blade");
       ob->map_skill("force","huntian-qigong");
       ob->prepare_skill("cuff","taizu-quan");

       ob->set("combat_exp",(int)me->query("combat_exp")*2);
       ob->set("max_neili",me->query("max_neili"));
       ob->set("neili",(int)me->query("max_neili")*2 - 1);    
       message_vision("һ����Ӱ��ɽ������,����������Ѿ���$N�����ڿ��쵶����֮�¡�\n",me);
       ob->kill_ob(me);
       remove_call_out("confirm");
       call_out("confirm",60,me);
       return 1;
}
int confirm()
 {
    object me,ob;
    me=this_player();
    ob=present("tian boguang",this_object());
if (!ob) return 1;
    if (me->is_ghost()||!me->is_fighting()){
       if(ob) destruct(ob);
       return 1;
    }
    message_vision(CYN"һ����ӰƮȻ���䣬������������Ҫָ��$N���У��ѵ���ʰ����$n�������?\n"NOR, me,ob);
    message_vision(CYN"$N��ʹһ�С��׺���ա������ű�ʹ���з����ǡ�����ʹһ�С������ա���\n"
                        +"������ʹ���ؽ�ʽ��������һ�������ϲ�����ʹ����ʮ����ʽ��\n"NOR,me);
    message_vision(CYN"$n �мܲ�ס��������ɽ����ȥ����������̾һ����ʧ��ɽ��\n"NOR,me,ob);
    destruct(ob); 
    if (!me->query("fengset")){
    write("��õ��������ָ�㣬�ٸй��������\n");
    me->add("kar",1);
    me->add("combat_exp",15000);
    me->set("fengset",1);
    }
this_object()->set("tbg",0);
this_object()->delete("tbg");
    me->delete_temp("mb");
    me->set_temp("met_feng",1);
   return 1;
   }

int valid_leave(object me, string dir)
{
	if ((me->query("family/family_name") == "��ɽ��") && (me->query("fengset"))&&(dir == "northdown"))
	{
		me->move(__DIR__"siguoya");
		me->delete_temp("mark/steps");
		return notify_fail("��ѭ�ŷ�������ٵĽݾ�һ���Ӿ�������˼���¡�\n");
	}
	return ::valid_leave(me, dir);

}
