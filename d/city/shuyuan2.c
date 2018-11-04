//Room: /d/city/shuyuan2.c

string look_shelf();

#define STOY_TOC "/doc/legend/toc"
#define STOY_DIR "/doc/legend/"
inherit ROOM;

void create()
{
        set("short", "��Ժ���");
        set("long", @LONG
��������Ժ��ͼ��ݣ�����������һ����Ⱦ�����ϵ����(shelf)��
�������е������ǵ���ѡ����¼�������еķ���������������ġ�ң
Զĥ��ȥ�Ĵ�˵��������Ķ�(read)����Щ���ϵĹ��¡�
LONG);
        set("item_desc", ([
            "shelf" : (: look_shelf :),
        ]));
        set("exits", ([
            "down" : __DIR__"shuyuan",
        ]));
	set("no_clean_up", 0);
        setup();
}

void init()
{
        add_action("do_read", "read");
}

string look_shelf()
{
        this_player()->start_more(read_file(STOY_TOC));
        return "\n";
}

int do_read(string arg)
{
        object me=this_player();
        if (arg == "" || file_size(STOY_DIR + arg) <= 0)
                return notify_fail("����û���Ȿ�顣\n");

        log_file("LIBRARY", sprintf("%s read %s.\n", me->query("name"), arg));
        me->start_more(read_file(STOY_DIR + arg));
        return 1;
}

