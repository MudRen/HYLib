// /u/dubei/sdxl/muwu
// by dubei
 
inherit ROOM;
int do_zhao(string arg);

void create()
{
        set("short","ľ��");
        set("long", @LONG
����һ����ͨ��Сľ�ݣ��������߰���ѷ���һЩ������
���õ���Ʒ�����ڹ��߰�����ǽ����һ�ѵ�ȼ��������Ȼ�ո�
Ϩ��
LONG                           
        );
 
        set("exits", ([
                "out" : __DIR__"conglin4",
 
        ]));
 
        set("zhi_count", 1);

        setup();

}

void init()
{
        add_action("do_zhao", ({"zhao","find"}));
}

int do_zhao(string arg)
{
        object me=this_player();

        if ( arg != "����֦" )
            return notify_fail("��Ҫ��ʲô��\n");
        if (query("zhi_count") > 0) 
          {
           message_vision("$N��ǽ���﷭��һЩ����֦��\n", me);
           add("zhi_count", -1);
 
           new(__DIR__"obj/kusz")->move(me);
          }
        else
           message_vision("$N������ȥʲôҲû���š�\n", me);
     return 1;
}
