#include <ansi.h>
// alias.c
#pragma save_binary
#include <command.h>
#define MAX_REPEAT 50
#define MAX_ALIASES 40
#define HISTORY_BUFFER_SIZE 10
mapping alias;
static string *history, last_input;
static int last_cmd, repeat_cnt = 0;
static int last_cmd_time,cmd_time=0,kill_time=0;
string process_input(string str)
{
    string *args, command, argstr,verb,arg,file,cmd;
    int i, j;
    object ob,dest;
    object me = this_player();
    if (!query_heart_beat(me))
    {
    write("������û�������������µ�½!!\n");
    "/cmds/usr/quithy"->main(me);
    }

    if( me->query_temp("disable_inputs") )   return HIR"ʲô��\n"NOR;
    if( me->query_temp("block_msg/all") )   return HIR"�㿴����ʲô,ʲô��������!\n"NOR;
    cmd_time++;
    if (time()-last_cmd_time<1){
            if (kill_time>4){
                tell_object( this_object(),HIR "\n����������ָ��,���ָ���ʱ�����!!!��\n�����Ӻ��Զ��ָ�\n" NOR);
                    seteuid(getuid());
                    dest = this_player();
//	            this_player()->set_temp("block_msg/all", 1);
                    this_player()->set_temp("disable_inputs",1);
                    this_player()->start_busy(50);
	            call_out("recoveralias", 120);
                    cmd_time=0;
                    kill_time=0;
            }
                        if (cmd_time>14){
                tell_object( this_object(), "\n���ָ����������ˡ�\n���ָ�ȡ����!\n"  );
                cmd_time=0;
                kill_time++;
            }
    }else   {
        cmd_time=0;
        if (time()-last_cmd_time>1)
                kill_time>0?kill_time--:0;
          else
                kill_time=0;
    }
    last_cmd_time=time();
 
    if( str==last_input ) {
        repeat_cnt++;
        if( repeat_cnt > MAX_REPEAT && !wizardp(this_object())) {
            tell_object( this_object(),
                HIR "\n�������˹�����ظ�ָ�\n"
                "\n���ָ���ʱ�����!!�����Ӻ��Զ��ָ�!!\n" NOR);
//	this_object()->set_temp("block_msg/all", 1);
        this_object()->set_temp("disable_inputs",1);
        this_object()->start_busy(50);
	call_out("recoveralias", 120);
          return "";
        }
    } else {
        repeat_cnt = 0;
        last_input = str;
    }
    if( str[0]=='!' ) {
        if( pointerp(history) && sizeof(history) ) {
            if( sscanf(str, "!%d", i) )
                str = (string)history[(HISTORY_BUFFER_SIZE + last_cmd - i) % HISTORY_BUFFER_SIZE];
            else
                str = history[last_cmd];
        } else
            return "";
    } else {
        if( !pointerp(history) ) history = allocate(HISTORY_BUFFER_SIZE);
        last_cmd = (last_cmd + 1) % HISTORY_BUFFER_SIZE;
        history[last_cmd] = str;
    }
    if( mapp(alias) ) {
        if( !undefinedp(alias[str]) )
            return replace_string( alias[str], "$*", "" );
        if( sscanf(str, "%s %s", cmd, argstr)==2 && !undefinedp(alias[cmd]) ) {
            cmd = replace_string( alias[cmd], "$*", argstr );
            args = explode(argstr, " ");
            if( (j = sizeof(args)) )
                for(i=0; i<j; i++)
                    cmd = replace_string( cmd, "$" + (i+1), args[i] );
            return cmd;
        }
    }
    command=(string)ALIAS_D->process_global_alias(str);

        if( this_object()->query_encoding() )
                str = LANGUAGE_D->toGB(str);

    if (!living(this_object())){
        if (sscanf(command,"%s %s",verb,arg)!=2) verb=command;
        file="/cmds/usr/"+verb+".c";
      if (file_size(file)>0){
         file->main(this_object(),arg);
         return "";
      }
        else if( EMOTE_D->do_emote( this_object(), verb, arg ) )
            return "";
        else if( CHANNEL_D->do_channel( this_object(), verb, arg ) )
            return "";
    }
    return command;
}
int set_alias(string verb, string replace)
{
    if( !replace ) {
        if( mapp(alias) ) map_delete(alias, verb);
        return 1;
    } else {
        if( !mapp(alias) ) alias = ([ verb:replace ]);
        else if( sizeof(alias) > MAX_ALIASES )
            return notify_fail("���趨�� alias ̫���ˣ�����ɾ��һЩ�����õġ�\n");
        else alias[verb] = replace;
        return 1;
    }
}
mapping query_all_alias()
{
    return alias;
}

void recoveralias()
{
//	this_object()->set_temp("block_msg/all", 0);
        this_object()->set_temp("disable_inputs",0);
//	this_player()->set_temp("block_msg/all", 0);
        this_player()->set_temp("disable_inputs",0);
     message("system", HIG "\n������ϵͳ�ָ������ָ��....\n\n" NOR,
		this_object());
}
