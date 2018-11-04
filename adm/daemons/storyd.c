// storyd.c

#include <ansi.h>

inherit F_DBASE;

private string *story_name = ({//ѡ�����
#if 1
        "new1",
        "new1",
        "new2",
        "new2",
        "new3",
        "new3",
        "new4",                
        "new4",                
        "new5",
        "new5",//10
        "new6",
        "new6",
        "new7",
        "new7",
        "new8",
        "new8",
        "new9",
        "new9",
        "new10",
        "new10",//20
        "new11",
        "new11",
        "new12",
        "new12",
        "new13",
        "new13",
        "new14",
        "new14",
        "new15",
        "new15",//30
        "new16",
        "new16",
        "laojun",
        "xiyou",
        "xiyou",
        "guanzhang",
        "nanji",
        "liandan",
	"caishen",
	"caishen",//40
	"zhengxi",
	"zhengxi",
	"zagang",
	"zagang",
	"songdai",
	"songdai",
	"niulang",
	"niulang",
	"pergive",
	"pergive",//50
	"kargive",
	"kargive",
	"neiligive",
	"neiligive",
#endif
        "normal",
});

private object  running_story;
private mapping history;
private int step;
int filter_listener(object ob);

void ready_to_start()
{
        remove_call_out("process_story");
        call_out("start_story", 2800);//���ʱ��
//        call_out("start_story", 3 + random(1));//���ʱ��
}
void go_on_process(object ob)
{
        remove_call_out("start_story");
        remove_call_out("process_story");
        call_out("process_story", 1, ob);
}

void create()
{
        seteuid(ROOT_UID);
        set("channel_id", "�¼�����");
        CHANNEL_D->do_channel( this_object(), "sys", "�¼�ϵͳ�Ѿ�������\n");

        history = allocate_mapping(sizeof(story_name));
        ready_to_start();
}

int clean_up()
{
        return 1;
}

object query_running_story()
{
        return running_story;
}

void start_story()
{
        string name;
        object ob;
        int i;

        ready_to_start();
        CHANNEL_D->do_channel( this_object(), "sys", "�¼�ϵͳ��ʼѡ���¼���\n");

        for (i = 0; i < 54; i++)
        {
                name = story_name[random(sizeof(story_name))];
                if (undefinedp(history[name]))
                        history += ([ name : 0 ]);

                if (time() - history[name] > 14400 || name == "normal")
                {
                        history[name] = (int)time();
                        break;
                }
        }

        if (i >= 54) return;

        CHANNEL_D->do_channel( this_object(), "sys", "�¼�ϵͳѡ�����¼�(" + name + ")��\n");

        name = STORY_DIR + name;
        if (ob = find_object(name))
                destruct(ob);

        catch(ob = load_object(name));
        running_story = ob;

        if (! objectp(ob))
                return;

        step = 0;
        go_on_process(ob);
}

void process_story(object ob)
{
        mixed line;
	object *listeners;
        string prompt;

        go_on_process(ob);

        if (! objectp(ob))
        {
                ready_to_start();
                return;
        }

        line = ob->query_story_message(step);
        step++;

        prompt = ob->prompt();
        if (! prompt) prompt = HIY "���������¡� " NOR;
        if (functionp(line)) catch(line = evaluate(line));
        if (stringp(line))
	{
		listeners = filter_array(users(), (: filter_listener :));
                message( "story",  prompt + WHT + line + "\n" NOR, listeners );
	}

        if (intp(line) && ! line)
        {
                ready_to_start();
                destruct(ob);
        }
}

int filter_listener(object ob)
{
	if (ob->query("env/no_story")) return 0;
	return 1;
}

void give_gift(string gift, int amount, string msg)
{
        int i;
        object ob;
        object env;
        object *players;

        players = users();
        if (sizeof(players) >= 5)
        {
                for (i = 0; i < 5; i++)
                {
                        ob = players[random(sizeof(players))];
                        if (wizardp(ob)) continue;
                                
                        env = environment(ob);
                        while (env && env->is_character())
                                env = environment(env);
                        if (env) break;
                }
                if (i >= 5) return;

                if (objectp(env))
                        tell_room(env, msg);
                for (i = 0; i < amount; i++)
                {
                        ob = new(gift);
                        ob->move(env);
                }
//	        CHANNEL_D->do_channel( this_object(),
//			"adm", sprintf(NOR WHT "��Ʒ%s" NOR WHT "������"
//				HIC "%s" NOR WHT "(%O" NOR WHT ")��\n" NOR,
//                               ob->name(), env->query("short"), env));
        }
}
