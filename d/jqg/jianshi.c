// jianshi.c ����
// By River 99/05/20
inherit ROOM;
#include <ansi.h>
string look_zhuo();
void create()
{
            set("short", HIW"����"NOR);
            set("long",@LONG
�����ǽ��ң�ֻ�����б��ϡ����ϡ����ϡ����С����䣬�����������У�
ʽ�����࣬ʮ֮�˾Ŷ��ǹŽ��������߳ߣ���̽����磬�е����ڰ߲�����
�ĺ�����ˡ�ȴ���ݽ����ڼ�һ��Ƭ���յĽ��ۣ���������Ҳ���յò��ơ�
LONG
    );
            set("item_desc", ([ 
                 "����" : (: look_zhuo :),
                 "zhuoyi" : (: look_zhuo :),
                 "�ݽ�":(: look_zhuo :),
                 "wujiao":(: look_zhuo :),
            ]));


            set("exits",([
                "south": __DIR__"lang5",
            ]));                         

            setup();
}

string look_zhuo()
{
         this_player()->set_temp("jqg/sword",1 );
         if (this_player()->is_busy())
          return "����æ���ء�\n";

         this_player()->start_busy(2);
          return "��ֻ���ݽ����ػ���֮��¶�����ν���(sword)����\n";
}

void init()
{
         object me=this_player();
         if (!me->query_temp("jqg/enter")){
         if ( me->query_skill("dodge",1) < 120){
         tell_object(me,HIR"\n���������������죬��ǰ�׹��������˱������Է�����������ͦ�����ݺύ��������ڡ�\n\n"NOR);
         tell_object(me,RED"������������������������˹��أ��Ѿ�������в���\n"NOR);
         me->set_temp("last_damage_from", "���л��ض�");
         me->die();
         }
         else {
         tell_object(me,HIR"\n���������������죬��ǰ�׹��������˱������Է�����������ͦ�����ݺύ��������ڡ�\n\n"NOR);
         tell_object(me,HIW"�㲻�Ų�æ������һ�������������𣬿���Ȼ������ſڵĻ��ء�\n\n"NOR);
         me->start_busy(2);
         me->set_temp("jqg/enter", 1);
         }
         }
         add_action("do_zhai","zhai");
}

int do_zhai(string arg)
{
         object jzj,snj,me = this_player();
         if(!me->query_temp("jqg/sword")) return 0;
         if (!arg || (arg != "sword"))
              return notify_fail("��Ҫժʲô����\n");
         if (me->is_busy() || me->is_fighting())
	      return notify_fail("����æ���ģ�\n");
         if( me->query("gender") =="����"
          && me->query("couple/couple_id")){
            jzj=new(__DIR__"npc/jzj");
          if(!clonep(jzj))
             return notify_fail("�������ˣ����ӽ��Ѹ����������ˡ�\n");  
if (this_object()->query("aget1"))
{
             destruct(jzj);
             return notify_fail("�������ˣ����ӽ��Ѹ�����ȡ���ˡ�\n");
             }

          if(clonep(jzj) && jzj->violate_unique()){
             destruct(jzj);
             return notify_fail("�������ˣ����ӽ��Ѹ�����ȡ���ˡ�\n");
             }
            message_vision("$N���ֵ�����ժ��һ�Ѿ��ӽ���\n"NOR,me);
            jzj->move(me);
            this_object()->set("aget1",1);
            me->delete_temp("jqg/sword");
            return 1;
            }
         if( me->query("gender") =="Ů��"
          && me->query("couple/couple_id")){
            snj=new(__DIR__"npc/snj");
          if(!clonep(snj))
             return notify_fail("�������ˣ���Ů���Ѹ����������ˡ�\n");  
if (this_object()->query("aget2"))
{
             destruct(snj);
             return notify_fail("�������ˣ���Ů���Ѹ�����ȡ���ˡ�\n");
             }

          if(clonep(snj) && snj->violate_unique()){
             destruct(snj);
             return notify_fail("�������ˣ���Ů���Ѹ�����ȡ���ˡ�\n");
             }
            message_vision("$N���ֵ�����ժ��һ����Ů����\n"NOR,me);
            snj->move(me);
            this_object()->set("aget2",1);
            me->delete_temp("jqg/sword");
            return 1;
            }
           else{
            me->delete_temp("jqg/sword");
            return notify_fail("�㷢��ԭ����ѽ������ʺ��Լ������ǰ��������˻�����\n");
            }
}
