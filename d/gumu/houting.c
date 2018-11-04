// houting.c ����
// Java Oct.10 1998

#include <ansi.h>
inherit ROOM;

int do_tang(string arg);
int do_niu(string arg);

void create()
{
        set("short", "����");
        set("long", @LONG
�����ǹ�Ĺ�ĺ������ܷ������ʵʵ��û��һ˿�ķ�϶���ڻ谵
�ĵƹ��£��㷢��ǽ��������һ���� (picture)���ƺ���һ�������
Ф�����������룬�ڷ��ż��߹ײ�(coffin)������ֻ��һ�߹ײĵ�
�װ�û�к��ϣ��ײ��к���տ���Ҳ����ǰ��д��һ�д��֣�zi����
�������ڶ�����һ���������� (westpic)�Ļ���������Ů�ɣ����ǹ�
Ĺ�ɵ�ʦ���ֳ�Ӣ��ʦ�����ŵ�Ф�񣬶��ࣨeastpic��������ȴ��һ
����ʿ��
LONG
        );

        set("exits", ([
                "north" : __DIR__"zhengting",
                "east" : __DIR__"gmqs",
        ]));

        set("item_desc", ([
               "westpic" : HIM"�����������һ����ʮ�����꣬���ڶԾ���ױ�����о���ӳ��Ů����ò������
��ü���ޣ��۽�ȴ��������һ��ɱ�������ǹ�Ĺ��ʦ���ֳ�Ӣ����һ����ʮ��
�����Ѿ�ߣ��ֳ����裬�����ź򣬺�̬���䣬�������������������С��Ů
��ʦ����\n"NOR,
               "eastpic" : HIC"���е���������ߣ���������������ʳָָ�Ŷ����ǣ�ֻ�Ǳ������⣬��òȴ
��������\n"NOR,
               "zi" : HIR"\t���ҹ�Ĺ�����������������񹦣�������ʦ��\n"NOR,
        "picture": "������һ�������ʿ�ı�Ӱ��������ʲô��ò��������һ��ָ�죬��
�����š�"+MAG"��������"NOR+"���������֡�\n",
        "coffin": "�ú���ʯ�����ɵĹײģ��װ���Ϻ󣬾�û��һ˿�ķ�϶�ˡ�\n"
        ]) );

        set("getbook",1);

        setup();
        //replace_program(ROOM);
}

void init()
{
         add_action("do_ketou", "ketou"); 
         add_action("do_tuo", "tuo");
        add_action("do_tang", "tang");
        add_action("do_niu", "niu");
}

int do_tang(string arg)
{
        object me=this_player();
        object ob;

        if( !arg || arg != "coffin" ) {
                return notify_fail("��Ҫ�����Ķ���\n");
        }

        if (query("getbook")>0) {
        message_vision("$N�ɽ��ײ��У��ѹװ���ϣ���ʱһƬ�ڰ����ƺ���쳾�����ˣ�\n",this_player());
        message_vision("������$N�ƺ������װ��ڱ��������֣�ϸϸ����������һͷд��\n", this_player());
        message_vision("��"+HIW"��Ů�ľ�����ѹȫ�棻����һ������������"NOR+"������ʮ�������֣�\n", this_player());
        message_vision("��һͷ������һЩͼ��֮��ķ��š�$N��֪���ԣ������������\n", this_player());
        message_vision("��������˵�������������ϲ�����ϸϸ�ؽ���������ȫ��������\n", this_player());
        message_vision("������������֮�䣬�ƺ������׽�����һ��͹��Ļ���(lock)��\n", this_player());

        if (random(21)>10)
                ob=new("/clone/book/jiuyin2");
        else
                ob=new("/clone/book/jiuyin1");
        ob->move(me);
        add("getbook",-1);
        }
        else {
        message_vision("$N�ɽ��ײ��У��ѹװ���ϣ���ʱһƬ�ڰ����ƺ���쳾������\n",this_player());
        message_vision("������$N�ƺ������װ��ڱ���ǰ�������֣��������ּ��Ѿ�����\n", this_player());
        message_vision("����ε��ˡ�ͻȻ�䣬�ƺ������׽�����һ��͹��Ļ���(lock)��\n", this_player());
        }

        me->set_temp("tmarks/��",1);
        return 1;
}

int do_niu(string arg)
{
        object me=this_player();

        if( !arg || arg != "lock" || me->query_temp("tmarks/��",1)<1) {
                return notify_fail("��ҪŤ��ʲô��\n");
        }

        message_vision("$N���ջ��أ���������Ť������Ȼ��׵�֨֨���죬�ѿ���һ��
\n",this_player());
        message_vision("�󶴣�$N����������ȥ��\n", this_player());
        me->move(__DIR__"mishi2");

        me->set_temp("tmarks/��",0);
        return 1;

}

 
int do_ketou(string arg)
{
          mapping fam;
          object me = this_player();
          object key;

        if ((!arg) || (arg != "westpic")) return 0;
          message_vision("$N�����򵹣�˫ϥ���أ�������������ʦ���ŵĻ������һ����ͷ. \n", me);
          me->add_temp("marks/ketou", 1);
        if (me->query_temp("marks/tuo") == 2 && me->query_temp("marks/ketou") == 4
          && (!(fam = me->query("family")) || fam["family_name"] != "��Ĺ��") && me->query("combat_exp") < 10000){
          me->set("family/family_name", "��Ĺ��");
          me->set("title", HIW"��Ĺ����"NOR);
          me->create_family("��Ĺ��", 5, "����");
          write(HIR"��ϲ����Ը��Ϊһ����Ĺ���ӡ�\n"NOR);
          me->delete_temp("marks/tuo");
          me->delete_temp("marks/ketou");
          return 1;
          }
     return 1;
}

int do_tuo(string arg)
{
           object me = this_player();
           if (me->query_temp("marks/tuo") == 2)
             return notify_fail("���ٹ���û�У�\n");
           if ( arg=="eastpic"){
           message_vision("$N���������Ļ���ݺ�����һ��. \n", me);
           me->add_temp("marks/tuo", 1);
           return 1;
           }
          return notify_fail("�㲻Ҫ������ٿ�ˮ����\n");
}
