// shiyao.c ʯ��
// By River 99.5.25
inherit ROOM;

#include <ansi.h>

void create()
{
        set("short",HIW"ʯ��"NOR);
        set("long",@LONG
��ת�����������ǰͻȻ����ҫĿ������һ����Ȼ���ɵ�ʯ�ߣ����
��ͷ�������и�Բ������Ĵ�ף��չ�ӿ���͸�������ֻ���Ǵ�����һ��
���ɣ���ʯ����صף����ڿ��д������У��������˾���Ҳδ��������̧ͷ
���Կ����ߴ�ʯ���ϰ���͹͹�����Ƶ��µĻ��ʯ�����չ������������˲�
�ٴ�����(tree)��
LONG
);

        set("item_desc",([
             "tree":"����һ������������֦Ҷïʢ�����������ӡ�\n",
             "zao":"����һ�ſŹ������ϣ�����ȥ�����ˣ�ʹ���̲�ס��ȥժ������\n",
        ]));

        set("outdoors","�����");

        set("exits",([
             "east":__DIR__"cave3",
        ]));

        set("objects",([
                __DIR__"npc/qqchi":1,
        ]));
          
        setup();
}

void init()
{
        add_action("do_climb", "climb");
        add_action("do_climb", "pa");
        add_action("do_zhai","zhai");
        add_action("do_cut", "bo");
        add_action("do_cuo", "cuo");
        add_action("do_zhe","zhe");
}

int do_zhai(string arg)
{
        object me = this_player();
        if (arg != "zao" || !arg) return 0;
        tell_object(me,"������ȥժ���ϵ����ӣ������ֱ���Ҫ�ٳ���ʮ�߲��У�\n");
        return 1;
}

int do_climb(string arg)
{
        object me,*ob;
        int i;
        me = this_player();
        if (! arg || arg != "shibi")
                return notify_fail("��Ҫ����������\n");
        if (me->is_busy() || me->is_fighting())
                return notify_fail("����æ���ģ�\n");
        ob = deep_inventory(me);
        i = sizeof(ob);
        while (i--)
        if (ob[i]->is_character())
                return notify_fail("�����ϱ���һ���ˣ��޷���������ȥ��\n");
        message("vison", me->name() + "��ס����������ʯ�ڣ�һ·������Ԯ��\n",environment(me), ({me}));
        tell_object(me,HIW"\n����ס����������ʯ�ڣ�һ·������Ԯ��\n\n"NOR);
        me->move(__DIR__"shibi");
        tell_room(environment(me), me->name() + "�������"HIW"ʯ��"NOR"����������\n", ({ me }));
        return 1;
}

int do_cut(string arg)
{
        object me = this_player();
        if (me->is_busy() || me->is_fighting())
                return notify_fail("����æ���ģ�\n");
        if (!arg || arg != "shupi")
                return notify_fail("��Ҫ��ʲô��\n");
        if (present("shupi suo", me))
                return notify_fail("���Ѿ�����Ƥ���ˣ�����Ҫ�ٰ���Ƥ�ˡ�\n");
        if(me->query_temp("jqg/fu"))
                return notify_fail("���Ѿ�������һ�˸��������м䣬������Ҫ��Ƥ�ˡ�\n");
        message("vison", me->name() + "�Ѿ��ش������ϰ�����Ƥ��\n",environment(me), ({me}));
        tell_object(me,"��Ѿ��ش������ϰ�����Ƥ��\n");
        me->add_temp("jqg/bo", 1);
        return 1;
}

int do_cuo(string arg)
{
        object me = this_player();
        if(!me->query_temp("jqg/bo")) return 0;
        if (me->is_busy() || me->is_fighting())
                  return notify_fail("����æ���ģ�\n");
        if(! arg || arg != "shupi")
                  return notify_fail("��Ҫ��ʲô? \n");
        if((int)me->query_temp("jqg/bo") < 8)
                  return notify_fail("�����Ƥ����������㹻��������������ȥ��\n");       
        message("vision", me->name() + "�Ѿ����������Ű���Ƥ���һ�����������ӡ�\n", environment(me),({me}));
        tell_object(me,"�����Ƥ��ʳ������Ѿ����������Ű���Ƥ���һ�����������ӡ�\n");
        me->delete_temp("jqg/bo");
        new(__DIR__"obj/changsuo")->move(me);
        me->start_busy(1);
        return 1;
}

int do_zhe(string arg)
{
        object me = this_player();
        if(! arg || arg !="shugan")
                return notify_fail("��Ҫ��ʲô��\n");
        if (me->is_busy() || me->is_fighting())
                return notify_fail("����æ���ģ�\n");
        if (present("zao shugan", me))
                return notify_fail("�㲻���Ѿ���������ô��\n");
        message("vision", me->name() + "����һ�������ɡ�\n",environment(me), ({me}));
        tell_object(me,"������һ��������֦�ɣ���Լһ����ߡ�\n");
        new(__DIR__"obj/shuzhi")->move(me);
        me->start_busy(1);
        return 1;
}
