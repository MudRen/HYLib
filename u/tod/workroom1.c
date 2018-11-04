// By Batman @ Freedom Studio 2001/6/6

inherit ROOM; 
#include <room.h> 
#include <ansi.h>
/*
string look_text(object me);
string look_drawing(object me);
string look_dragon(object me);
string look_tiger(object me);
string look_phoenix(object me);
string look_turtle(object me);
string look_bian(object me);
string look_door(object me);
string look_shelf(object me);

int draw, l, h, q, w, d, t, f, g; 
*/

void create() 
{ 
        set("short", HIC"��"HIR"��"HIG"��"NOR);
        set("long", @LONG
���������ее����ɸ󣬴˴��������£�����ľ��·������ڱ̺�����

֮�ϡ�ǽ�Ϲ���һЩ��(text)��(drawing)�����ڵ��ĸ������Ϸֱ�������
��(dragon)���׻�(tiger)����ȸ(phoenix)������(turtle)��յʯ�ơ�����
�����ʯ̨���аѽ�û�����У�ֻ�н���¶�����档���Ӷ����п����(bian)��
��������ľ��(door)�����ﻹ�кü������(shelf)��
LONG
        );
/*
        set("item_desc", ([sizeof() == 9 "text": (: look_text :),
        "drawing": (: look_drawing :),
        "dragon": (: look_dragon :),
        "tiger": (: look_tiger :),
        "phoenix": (: look_phoenix :),
        "turtle": (: look_turtle :),
        "bian": (: look_bian :),
        "door": (: look_door :),
        "shelf": (: look_shelf :),]));
*/
        set("exits", ([ /* sizeof() == 5 */
                "gumu" : "/d/gumu/damen",
                "taohua" : "/d/taohua/jcting2",
                "down" : "/d/wizard/wizard_room",
                "yangzhou" : "/d/city/ylting2",
                "south" : __DIR__"woshi",
        ]));
        set("objects", ([
            "/clone/money/1000-cash" : 1000,

                __DIR__"npc/maggie" : 1,
                __DIR__"npc/ada" : 1,
                __DIR__"npc/doma" : 1,
]) );

        set("no_clean_up", 1);
setup();
}
/*

void init()
{
        add_action("do_fire", "dian");
        add_action("do_putout", "xi") ;
        add_action("do_get", "ba") ;
        add_action("do_xian", "xian") ;
        add_action("do_plug", "plug") ;
        add_action("do_plug", "cha") ;
        add_action("do_plug", "insert") ;
        add_action("do_pick", "pick") ;
        add_action("do_pick", "na") ;
        add_action("go_maggie","zong");
        switch( random(6) )

        {       case 0 : draw=0;break;
                case 1 : draw=1;break;
                case 2 : draw=2;break;
                case 3 : draw=3;break;
                case 4 : draw=4;break;
                case 5 : draw=5;break;
        }
        switch( random(16) )
        {       case 0 : l=0;h=0;q=0;w=0;break;
                case 1 : l=0;h=0;q=0;w=1;break;
                case 2 : l=0;h=0;q=1;w=0;break;
                case 3 : l=0;h=0;q=1;w=1;break;
                case 4 : l=0;h=1;q=0;w=0;break;
                case 5 : l=0;h=1;q=0;w=1;break;
                case 6 : l=0;h=1;q=1;w=0;break;
                case 7 : l=0;h=1;q=1;w=1;break;
                case 8 : l=1;h=0;q=0;w=0;break;
                case 9 : l=1;h=0;q=0;w=1;break;
                case 10 : l=1;h=0;q=1;w=0;break;
                case 11 : l=1;h=0;q=1;w=1;break;
                case 12 : l=1;h=1;q=0;w=0;break;
                case 13 : l=1;h=1;q=0;w=1;break;
                case 14 : l=1;h=1;q=1;w=0;break;

                case 15 : l=1;h=1;q=1;w=1;break;
        }
        switch( draw )
        {       case 0 : f = q; g = w;
                switch (l)
                {case 0 : d = 1;break;case 1 : d = 0;break;}
                switch (h)
                {case 0 : t = 1;break;case 1 : t = 0;break;};break;
                case 1 : t = h; g = w;
                switch (l)
                {case 0 : d = 1;break;case 1 : d = 0;break;}
                switch (q)
                {case 0 : f = 1;break;case 1 : f = 0;break;};break;
                case 2 : t = h; f = q;
                switch (l)
                {case 0 : d = 1;break;case 1 : d = 0;break;}
                switch (w)
                {case 0 : g = 1;break;case 1 : g = 0;break;};break;
                case 3 : d = l; g = w;
                switch (h)
                {case 0 : t = 1;break;case 1 : t = 0;break;}
                switch (q)
                {case 0 : f = 1;break;case 1 : f = 0;break;};break;

                case 4 : d = l; f = q;
                switch (h)
                {case 0 : t = 1;break;case 1 : t = 0;break;}
                switch (w)
                {case 0 : g = 1;break;case 1 : g = 0;break;};break;
                case 5 : d = l; t = h;
                switch (q)
                {case 0 : f = 1;break;case 1 : f = 0;break;}
                switch (w)
                {case 0 : g = 1;break;case 1 : g = 0;break;};break;
        }
        
}


string look_text(object me)
{
        return HIG"        ɹ\n        ��\n��      ��\n��      ��\n\n��  ��  ��\n��  ��  ��\n��  ��  ��\n    ��  ��\n    ��  ˮ\n    ��  ��\n\n    ��\n    ��\n    ֱ\n    ��\n    |\n"NOR;
}

string look_bian(object me)
{
        return HIY"****************\n*  "HIG"��  "HIR"��  "HIC"��  "HIY"*\n****************\n"NOR;

}

string look_door(object me)
{
        if (!query("exits/west"))
                return "����һ�Ⱥܺ��ľ�ţ��������ƣ����ָ����Ʋ�����\n";
        else return "����ľ�źܺ񣬲�֪�����������\n";       
}

string look_shelf(object me)
{
        if (!query("exits/west"))
                return "����ϰ������飬���������ƺ�ȱ��һ����\n";
        else return "����ϰ������顣\n";       
}

string look_drawing(object me)
{
       switch (draw)
        { case 0 : return HIY"����һ�����ڻ�Ծͼ��\n"NOR;       break;
        case 1: return HIY"����һ���������ͼ��\n"NOR;break;
        case 2: return HIY"����һ�������ĺ�ͼ��\n"NOR;break;
        case 3: return HIY"����һ�����������ǰ���֮�������֮����\n"NOR;break;

        case 4: return HIY"����һ�������������ͻ������꣬��ֵ���Ʒ��\n"NOR;break;
        case 5: return HIY"����һ�������������ڹ����ˣ���û�и��\n"NOR;break;}
}

string look_dragon(object me)
{
       switch (d)
        { case 0 : return HIC"����һյ��������ͷ��ʯ�ƣ�������ĵ�о���ˡ�\n"NOR; break;
        case 1: return HIC"����һյ��������ͷ��ʯ�ƣ�������ĵ�оȼ�š�\n"NOR;  break;}

}
string look_tiger(object me)
{
       switch (t)
        { case 0 : return HIW"����һյ���а׻�ͷ��ʯ�ƣ�������ĵ�о���ˡ�\n"NOR; break;
        case 1: return HIW"����һյ���а׻�ͷ��ʯ�ƣ�������ĵ�оȼ�š�\n"NOR;  break;}

}
string look_phoenix(object me)
{
       switch (f)
        { case 0 : return HIR"����һյ������ȸͷ��ʯ�ƣ�������ĵ�о���ˡ�\n"NOR; break;
        case 1: return HIR"����һյ������ȸͷ��ʯ�ƣ�������ĵ�оȼ�š�\n"NOR;  break;}


}
string look_turtle(object me)
{
       switch (g)
        { case 0 : return HIB"����һյ��������ͷ��ʯ�ƣ������ĵ�о���ˡ�\n"NOR; break;
        case 1: return HIB"����һյ��������ͷ��ʯ�ƣ������ĵ�оȼ�š�\n"NOR;  break;}

}

int do_fire(string arg)
{
        object me;
        me = this_player();
        if ( !arg || ( ( arg != "dragon") && ( arg != "tiger") && ( arg != "phoenix") && ( arg != "turtle") ) )
                return notify_fail ("��Ҫ��ʲô��\n");
        if (arg == "dragon")
        {
                if (d == 1) 
                        return notify_fail ("��յ��ԭ�������š�\n");
                else
                {
                        message_vision (HIC"$Nȡ�����ۣ��������Ƶ�ȼ��\n"NOR, me);

                        d = 1;
                        return 1;
                }
        }
        else if (arg == "tiger")
        {
                if (t == 1)
                        return notify_fail ("��յ��ԭ�������š�\n");
                else
                {
                        message_vision (HIW"$Nȡ�����ۣ����׻��Ƶ�ȼ��\n"NOR, me);
                        t = 1;
                        return 1;
                }
        }
        else if (arg == "phoenix")
        {
                if (f == 1)
                        return notify_fail ("��յ��ԭ�������š�\n");
                else
                {
                        message_vision (HIR"$Nȡ�����ۣ�����ȸ�Ƶ�ȼ��\n"NOR, me);
                        f = 1;

                        return 1;
                }
        }
        else if (arg == "turtle")
        {
                if (g == 1)
                        return notify_fail ("��յ��ԭ�������š�\n");
                else
                {
                        message_vision (HIB"$Nȡ�����ۣ�������Ƶ�ȼ��\n"NOR, me);
                        g = 1;
                        return 1;
                }
        }       
        return 1;
}

int do_putout(string arg)
{
        object me;
        me = this_player();
        if ( !arg || ( ( arg != "dragon") && ( arg != "tiger") && ( arg != "phoenix") && ( arg != "turtle") ) )
                return notify_fail ("��Ҫ��ʲô��\n");

        if (arg == "dragon")
        {
                if (d == 0)
                        return notify_fail ("��յ���Ѿ����ˡ�\n");
                else
                {
                        message_vision (HIC"$N��������Ϩ���ˡ�\n"NOR, me);
                        d = 0;
                        return 1;
                }
        }
        else if (arg == "tiger")
        {
                if (t == 0)
                        return notify_fail ("��յ���Ѿ����ˡ�\n");
                else
                {
                        message_vision (HIW"$N���׻���Ϩ���ˡ�\n"NOR, me);
                        t = 0;
                        return 1;
                }
        }
        else if (arg == "phoenix")

        {
                if (f == 0)
                        return notify_fail ("��յ���Ѿ����ˡ�\n");
                else
                {
                        message_vision (HIR"$N����ȸ�Ƶ�Ϩ���ˡ�\n"NOR, me);
                        f = 0;
                        return 1;
                }
        }
        else if (arg == "turtle")
        {
                if (g == 0)
                        return notify_fail ("��յ���Ѿ����ˡ�\n");
                else
                {
                        message_vision (HIB"$N�������Ϩ���ˡ�\n"NOR, me);
                        g = 0;
                        return 1;
                }
        }       
        return 1;
}


int do_get(string arg)
{
        object me, ob, room;
        me = this_player();
        if(!( room = find_object("/u/batman/woshi")) );
                room = load_object("/u/batman/woshi");
        if ( !arg || ( arg != "sword") )
                return notify_fail ("��Ҫ��ʲô��\n");
        if ( ( d != l ) || ( t !=h ) || ( f != q ) || ( g != w ) )
                return notify_fail ("��ʹ���˳��̵������������޷��ѽ��γ���\n");
        if((sizeof(children("/u/batman/obj/skysword"))>1) || (sizeof(children("/u/batman/obj/qksword"))>1) || (room->query("hole") == 2))
                message_vision ("$N�γ�һ���������������$N̾�˿����ְ������ԭ����\n"NOR, me);
         else
        {
                message_vision (HIC"ͻȻ�䣬���������д��˸�������$N�ѽ�ʯ̨�ϵĹŽ����˳�����\n"NOR, me);
                ob=new(__DIR__"obj/skysword");
                ob->move(me);
        }
return 1;
}

int do_xian(string arg)

{
        object me, ob, room;
        me = this_player();
        if(!( room = find_object("/u/batman/woshi")) );
                room = load_object("/u/batman/woshi");
        if ( !arg || ( arg != "text") )
                return notify_fail ("��Ҫ��ʲô��\n");
        if ( ( d != l ) || ( t !=h ) || ( f != q ) || ( g != w ) )
                return notify_fail ("���У��ֻ���Ū���ġ�\n");
        if((sizeof(children("/u/batman/obj/groundsword"))>1) || (sizeof(children("/u/batman/obj/qksword"))>1) || (room->query("hole") == 2))
                message_vision ("$N�����ֻ�������ʲôҲû�У�$N���ú�ʧ����\n"NOR, me);
        else
        {
                message_vision (MAG"ͻȻ�䣬���΢΢������һ�£�$N���ֻ������ҵ�һ�ѹŽ���\n"NOR, me);
                ob=new(__DIR__"obj/groundsword");
                ob->move(me);
        }
return 1;
}

int go_maggie(string arg)
{
        object me;

        me = this_player();
        if ( !arg || ( arg != "bian") )
                return notify_fail ("��Ҫ��ʲô��\n");
        else
        {
                int mo = this_player()->query_skill("dodge");
                if ( mo >= 10 )
                {
                        message_vision ("$N��ƮƮ�������ɣ������Һ�\n",me);
                        tell_room(__DIR__"bian", me->query("name")+"����������\n");
                        me->move(__DIR__"bian");
                }
                else message_vision ("$Nʹ����ס��һ�ģ����ˤ�˸�����ʺ��\n",me);
        }
        return 1;
}

int do_plug(string arg)
{
        object me, obj;
        string item, target;
        me = this_player();
        if (!arg || (sscanf(arg, "%s on %s", item, target)!=2 ))

                return notify_fail ("��Ҫ��ʲô��ʲô�ϣ�\n");
        if ((item != "book") || (target != "shelf"))
                return notify_fail ("��Ҫ��ʲô��ʲô�ϣ�\n");
        if (! obj = present (item, me))
                return notify_fail("������û������������\n");
        if (obj->query("name") != HIY"С˵��"NOR)
                return notify_fail("�Ȿ��̫���ˣ��Ų�����\n");
        if (query("exits/west"))
                return notify_fail("�Ѿ��Ų����ˡ�\n");
        message_vision("$N��$n��������ܵĿ�λ�ϣ�ľ�ž�Ȼ���ˡ�\n", me, obj);
        set("exits/west", __DIR__"ada/workroom");
        destruct(obj);
        return 1;
}

int do_pick(string arg)
{
        object me, obj;
        me = this_player();
        if(!arg || (arg != "book"))
                return notify_fail("��Ҫ��ʲô��\n");
        if ((sizeof(children("/u/batman/maggie/obj/book")) > 1) || (!query("exits/west")))
                message_vision("$N�������ȡ��һ���飬ԭ���Ǳ��ֵ䣬$N�ַ��˻�ȥ��\n", me);

        else
        {
                obj = new(__DIR__"maggie/obj/book");
                message_vision("$N�������ȡ��һ���飬�����ľ��ͻȻ�����ˡ�\n", me);
                obj->move(me);
                delete("exits/west");
        }
        return 1;
}

*/
