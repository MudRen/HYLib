// Room: /d/gaochang/zoulang1.c

inherit ROOM;


string look_writing();


void create()
{
        set("short", "����");
        set("long", @LONG
�����ǵ������ȡ�����һ��֧������ĸ�ǽ�ϣ���һ������
���ߵ��õ��ݶ�����������������������Ҳ�ò�������˸���
�����ͼ�Σ�ÿ�����ƺ�������˵һ���渶��˵Ĺ��¡�
LONG
        );

        set("exits", ([
                "southeast" : __DIR__"zoulange",
                "southwest" : __DIR__"zoulangw",
                "north" : __DIR__"mishi",
        ]));

        set("item_desc",([
                "writing"                :        (: look_writing :),
        ]));
   set("objects" , ([
     __DIR__"npc/wuaer" : 1,
   ]));
setup();
}
int valid_leave(object me, string dir)
{
        if (dir == "north" && (me->query_cor()<25) && !wizardp(me))
                return notify_fail("\nͻȻ֮�䣬ǰ��һ����ɭɭ�������ȵ���
�����������Ѱ���������ס��һǧ�꣬˭Ҳ�����������ҡ���һ���󵨹��������̾�
 ������\n
��ֻ������ͷһ��������ֱ���£���Ҳ��ǰ�߲���һ����\n ");
        return 1;
}

