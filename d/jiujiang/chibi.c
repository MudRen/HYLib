
#include <ansi.h>

inherit ROOM;


void create ()
{
  set ("short","�ų��ս��");
  set ("long", @LONG
��ڹų����ߣ�Ե���������������������������ء���������ʮ
���꣬��Ȩ���������ֿ��ܣ��ڵ��س����ﻮ�������񡢳�������
�ġ���ڴ�ս����һ�ٿ����˶������ֵľ��棬���й���ʷ�������ش�
Ӱ�졣
LONG);

  set("exits", ([ 

  "north":__DIR__"xiaojing1",
          ]));

  set("valid_startroom", 1);
  set("outdoors","jiang");
  setup();
 
}

void init()
{
   add_action("do_linghui","linghui");
 
}

int do_linghui(string arg)
{
   object ob;
   string time,oldtime,msg;
   
   ob=this_player();
   
   if(!ob->query_temp("bai_fu_action7"))
    return 0;
   if(ob->query("execute_quest/yijianshu_fail"))
   return notify_fail("��ʲôҲ��᲻������\n");
   if(!arg||arg!="�Ľ���")
   return notify_fail("��Ҫ���ʲô��\n");
   if(time()-ob->query_temp("bai_fu_action7_busy")<120)
   return notify_fail("����Ѫ�������޷�������ᣡ\n");
   time=NATURE_D->game_time();
   
   if(ob->query_temp("bai_fu_action8")){
      oldtime=ob->query_temp("bai_fu_action8");
      if(time[sizeof(time)-8..sizeof(time)]!=
         oldtime[sizeof(oldtime)-8..sizeof(oldtime)]
        ){
          msg="���Ź�ս������ַ��������븵���ֵ�һս������ܵ������ִ����Ľ���\n"+
              "�ı��⡣û���㹻���������㽫���������������񼣵�Ȩ����\n";          
          tell_object(ob,msg);
          ob->set("execute_quest/yijianshu_fail",1);
          return 1;
      }
      msg="����Լ���ܵ����������������������Ӻ͸�������������Ļ�Ҷ�����ٿݣ�\n"+
          "���µ�����ȴ��Զ���档\n";
      ob->delete_temp("bai_fu_action7");
      ob->delete_temp("bai_fu_action8");
      ob->delete_temp("bai_fu_action7_busy");
      ob->set("execute_quest/yijianshu",1);
      tell_object(ob,msg);
      return 1;
  }
  msg="���Ź�ս������ַ��������븵���ֵ�һս������ܵ������ִ����Ľ���\n"+
              "�ı��⡣û���㹻���������㽫���������������񼣵�Ȩ����\n";
  tell_object(ob,msg);
  ob->set_temp("bai_fu_action8",time);
  ob->set_temp("bai_fu_action7_busy",time());
  return 1;
}